# 🎓 Univent Tracker  
*A University Events Management System built in C++*  

![C++](https://img.shields.io/badge/language-C++-blue.svg)  
![Status](https://img.shields.io/badge/status-Active-success.svg)  
![Contributors](https://img.shields.io/badge/contributors-4-brightgreen.svg)  
![Platform](https://img.shields.io/badge/platform-Desktop-lightgrey.svg)  

---

## 🧠 Overview  
**Univent Tracker** is a **C++-based console application** designed to help university students stay informed about **past, ongoing, and upcoming events**.  
The system provides functionalities to **insert, delete, search, sort, and display** event information — all stored persistently using **file handling**.  

In large universities, multiple departments often conduct events simultaneously and students can **miss out on opportunities** due to a lack of centralized event tracking. Univent Tracker solves this by maintaining a structured, offline record of all events.

---

## 💡 Features  
- 📅 **Insert New Events** — Add event name, date, and venue.  
- 🗑️ **Delete Events** — Remove outdated or canceled events.  
- 🔍 **Search Events** — Quickly find events by name, category, or date.  
- ↕️ **Sort Events** — Organize events chronologically using date sorting.  
- 💾 **File Handling** — Persistent storage so data remains between sessions.  
- 🧮 **Auto Event Counter** — Automatically tracks total number of events added.  

---

## ⚙️ Tech Stack  
| Component | Description |
|-----------|-------------|
| **Language** | C++ |
| **Paradigm** | Object-Oriented Programming |
| **Core Concepts** | Classes & Objects, File Handling, Encapsulation, I/O Streams |
| **Platform** | Console-based Desktop Application |

---

## 🧩 Project Structure  
Typical layout:

Univent-Tracker/
├─ main.cpp # Main control flow & menu

├─ Event.h # Event class declaration

├─ Event.cpp # Event class definitions (setters/getters/display)

├─ Functions.h # Declarations for insert/delete/search/sort/display

├─ Functions.cpp # Implementations (includes file handling)

├─ main.h # extern declarations for shared globals (if used)

├─ events.txt # Persistent storage (created at runtime)

└─ README.md

---

## 👩‍💻 Team BeyondGeeks  

| Role | Name |
|------|------|
| **Team Lead** | Parul Prashar |
| **Team Members** | Amneet Kaur • Khushpreet Kaur • Manroop Kaur (6) • Manroop Kaur (60) |

---

## 🧪 How to Build & Run (Local)

1. Clone the repository:
git clone https://github.com/yourusername/Univent-Tracker.git
cd Univent-Tracker
2. Compile with g++ (Windows/MinGW, Linux, or macOS with g++ installed):
g++ main.cpp Functions.cpp Event.cpp -o univent
3. Run the executable:
main.exe

---

## File Format Notes

Events are stored in events.txt. Each event is saved as a single line, for example:

0|Tech Fest|2025-10-30|Auditorium
1|Hackathon|2025-11-05|Lab 3

We use | as a delimiter: ID|Name|Date|Venue.

---

## 🛠️ Where to Modify / Extend

Event.h / Event.cpp —> modify event attributes and their getters/setters.

Functions.cpp —> implement or update logic for insertion, deletion, searching, sorting, and file I/O.

main.cpp —> change UI/menu flow or add program-level orchestration (load/save count on startup/exit).

events.txt —> data file (created/updated by the program).

---

## 📚 Learning Outcomes

Practical experience with file handling in C++.
Applying OOP principles in a real project.
Team collaboration, modular design, and version control use (git).
Handling persistence and simple data validation (dates, IDs).

---

## 🏫 Academic Context
This project was developed as part of a semester mini-project for the Computer Science & Engineering program. It demonstrates practical OOP and file management skills in C++.

---

## Contact
Team Lead: Parul Prashar — [parulprashar018@gmail.com or LinkedIn]
