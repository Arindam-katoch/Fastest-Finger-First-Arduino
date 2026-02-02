# Fastest Finger First Game

2-player Arduino reaction game: Both press to start countdown (reds > blues > green), first buzzer wins!

## Features
- Debounced buttons (millis()-based)
- Symmetric LED countdown
- Loud active buzzer
- Auto-restart

## Wiring
| Pin | Component |
|-----|-----------|
| 2   | Player 1 button |
| 3   | Player 2 button |
| 4,8 | Red LEDs (330Ω resistors) |
| 5,7 | Blue LEDs |
| 6   | Green LED |
| 9   | Buzzer (+ to pin, - to GND) |

Upload to Arduino IDE and play!
