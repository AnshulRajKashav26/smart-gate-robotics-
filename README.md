# Smart Gate System — Robotics Assignment

A virtual smart gate system that detects vehicles using an ultrasonic sensor, opens automatically, and closes only when the path is clear.

---

## Project Structure

| File | Description |
|------|-------------|
| `sketch.ino` | Arduino C++ code for the Smart Gate logic |
| `diagram.json` | Wokwi circuit wiring (HC-SR04 + Servo + LED) |
| `blockly_smart_gate.txt` | Custom Blockly block definition + JS generator |
| `smart_gate_dashboard.html` | Live web dashboard with simulated sensor trigger |
| `libraries.txt` | Arduino libraries used |

---

## Part 1 — Hardware Simulation (Wokwi)
link -
**Platform:** [Wokwi.com](https://wokwi.com)  
**Components:**
- Arduino Uno
- HC-SR04 Ultrasonic Distance Sensor (TRIG → D9, ECHO → D10)
- Servo Motor — acts as the gate (Signal → D6)
- LED with 220Ω resistor — blinks while gate is in motion (D13)

**Logic:**
1. Sensor continuously reads distance
2. If distance < 50cm → vehicle detected → gate opens (servo to 90°)
3. LED blinks for 5 seconds while gate is open
4. After 5 seconds → checks if path is clear
5. If clear (distance > 50cm) → gate closes (servo to 0°), LED off
6. If blocked → gate stays open

---

## Part 2 — Blockly Custom Block

Custom block called `open_gate_with_speed` defined in JavaScript.

- Takes a **speed input (1–10)**
- Generates `servo.write(90);` with a proportional delay
- Speed 1 = 1000ms delay (slow), Speed 10 = 100ms delay (fast)

See `blockly_smart_gate.txt` for the full JSON block definition and JS generator code.

---

## Part 3 — Web Dashboard

A single-page HTML/CSS/JS dashboard built with Tailwind CSS.

**Features:**
- Live feed status label: `Gate Closed` → `Gate Opening...`
- Animated gate arm visual
- Distance bar with color coding (green/yellow/red)
- Event log with timestamps
- Simulated sensor slider (0–400cm)
- Vehicle count metric
- LED status indicator

Open `smart_gate_dashboard.html` directly in any browser — no backend needed.

---

## Tech Stack

- Arduino C++ (Servo library)
- Wokwi Simulator
- Blockly JavaScript API
- HTML / Tailwind CSS / Vanilla JS

---

## Author

Anshul Raj
Mechatronics Engineering  
Assignment submitted for: Robotics Role — APTCODER
