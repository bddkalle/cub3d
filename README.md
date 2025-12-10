# cub3D

**Raycasting-Engine (2.5D) in C — Projekt in Entwicklung**

Dieses Projekt implementiert eine einfache 2.5D-Raycasting-Engine (inspiriert von klassischen Wolfenstein-/DOOM-Techniken) in C. Ziel ist es, die mathematischen und low-level-technischen Grundlagen der Echtzeit-Rendering-Pipelines zu verstehen und praktisch umzusetzen: Strahlen (Rays) werfen, Distanzen berechnen, Wand-Projektion und Textur-Mapping.

> Hinweis: Dieses Repo befindet sich aktiv in Entwicklung. Issue-/PR-Contributions sind willkommen.

---

## Inhaltsverzeichnis
- [Kurzüberblick](#kurzüberblick)  
- [Status / Roadmap](#status--roadmap)  
- [Voraussetzungen](#voraussetzungen)  
- [Quickstart / Build](#quickstart--build)  
- [Beispielnutzung / Controls](#beispielnutzung--controls)  
- [Architektur & Ordnerstruktur](#architektur--ordnerstruktur)  
- [Tests & Debugging](#tests--debugging)  


---

## Kurzüberblick
`cub3D` ist eine minimalistische 2.5D-Engine, umgesetzt in C. Sie liest eine tile-basierte Karte ein und rendert eine begehbare 3D-ähnliche Szene mittels Raycasting. Das Projekt dient als Lernprojekt für Grafikgrundlagen, Geometrie/Trigonometrie, Performance-Optimierung sowie low-level C-Programmierung.

---

## Status / Roadmap
**Aktueller Stand (in Arbeit):**
- [x] Grundlegende Raycasting-Loop & Wandprojektion  
- [x] Playerbewegung & Kollisionserkennung (Basis)  
- [ ] Textur-Mapping (In Arbeit / teilweise implementiert)  
- [ ] Sprites / Objekte (geplant)  
- [ ] Performance-Optimierungen & Frame-Limit  
- [ ] Robustere Map-Parser / Fehlerbehandlung  
- [ ] Unit/Integration Tests & CI

---

## Voraussetzungen
- C-Compiler (gcc/clang) mit C99/C11-Support  
- make  
- **Grafikbibliothek**: eine einfache 2D-Grafikbibliothek ist nötig (z. B. *MiniLibX* (MLX) oder eine X11-kompatible Bibliothek). Stelle sicher, dass auf deinem System die benötigten Dev-Pakete installiert sind (z. B. X11-Headers auf Linux).  
- Optional: `valgrind` für Speicherchecks, `gdb` für Debugging.

---

## Quickstart / Build

**1) Repository klonen**
```bash
git clone https://github.com/bddkalle/cub3d.git
cd cub3d
```

**2) Build***
Falls deine Grafikbibliothek separat gebaut werden muss:
```bash
make setup
```
Zum Kompilieren des Projekts:
```bash
make
```
Erwartetes Ergebnis: ein Binary (z. B. ./cub3D) im Projektordner.

**3) Ausführen**
```bash
./cub3d maps/example.cub
```

---

## Beispielnutzung / Controls
Standard-Kontrollen (kann je nach Implementation variieren):
- W / S — vorwärts / rückwärts
- A / D — seitwärts strafing (optional)
- Pfeiltasten ← → — Rotation / Blickrichtung ändern
- ESC — Programm beenden

Beispiel:
```bash
./cub3d maps/level01.cub
# dann im Fenster: W A S D oder Pfeil rechts/links zum bewegen
```

---

## Architektur & Ordnerstruktur
```bash
cub3d/
 ├── src/              # Quellcode (raycasting, player, rendering, parser, utils)
 ├── includes/         # Headerdateien
 ├── maps/             # Beispiel-Maps (.cub Dateien)
 ├── textures/         # Texturdateien (BMP/PNG) falls verwendet
 ├── lib/               # optionale Bibliotheken / submodules (z. B. libmlx)
 ├── Makefile
 └── README.md
```
Wichtige Module:
- `raycasting.c` / `ray.c`: Kernalgorithmus — Strahlen aussenden, Wandkollision, Distanzberechnung
- `render.c`: Wandprojektion und Pixel-/Line-Drawing (ggf. texture mapping)
- `player.c`: Player-Position, Bewegung, Kollisionsabfrage
- `parser.c`: Mapparser (Lese .cub Dateien, Validierung)
- `utils/`: Mathematische Hilfsfunktionen, Fehlerhandling, Farb-Utilities

---

## Tests & Debugging
- **Valgrind:**
```bash
  valgrind --leak-check=full --show-leak-kinds=all ./cub3d maps/example.cub
```

- **GDB:**
```bash
  gdb --args ./cub3d maps/example.cub
```
