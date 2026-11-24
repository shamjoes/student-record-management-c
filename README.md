README.md
# Student Record Management System in C

A modular, command-line **Student Record Management System** written in C. Built around dynamic **Singly Linked Lists (SLL)**, persistent binary/text file storage, and a color-coded **ANSI terminal interface**.

---

## Features

- **Record Management (CRUD):** Add new student records, display formatted student tables, modify existing entries by roll number or name, and delete individual, duplicate-name, or all records with proper heap memory cleanup (`free`).
- **Linked List Operations:** Sort student records, reverse the singly linked list in place, and search records dynamically.
- **File Persistence:** Automatically save and reload student records across sessions using `student.dat`.
- **ANSI-Styled Terminal UI:** Clean tabular output and highlighted prompts using ANSI escape sequences.

---

## Project Structure

| File | Description |
| :--- | :--- |
| `student.h` | Structure definitions, ANSI color macros, and function prototypes |
| `stud_main.c` | Main menu loop, user input handling, and program entry point |
| `stud_add.c` | Dynamic node allocation and student record insertion |
| `stud_show.c` | Formatted tabular display of linked list records |
| `stud_mod.c` | Search and modification of existing student records |
| `stud_del.c` | Deletion by roll number, duplicate name resolution, and full list cleanup |
| `stud_save.c` | File I/O routines (`fscanf` / `fprintf`) for persisting records to `student.dat` |
| `Makefile` | Automated compilation with `gcc -Wall -Wextra` |

---

## Build & Run

1. Compile the project:
   ```bash
   makecat << 'EOF' > README.md
Student Record Management System in C

A modular, command-line Student Record Management System written in C. Built around dynamic Singly Linked Lists (SLL), persistent binary/text file storage, and a color-coded ANSI terminal interface.



Features

- **Record Management (CRUD):** Add new student records, display formatted student tables, modify existing entries by roll number or name, and delete individual, duplicate-name, or all records with proper heap memory cleanup (`free`).
- **Linked List Operations:** Sort student records, reverse the singly linked list in place, and search records dynamically.
- **File Persistence:** Automatically save and reload student records across sessions using `student.dat`.
- **ANSI-Styled Terminal UI:** Clean tabular output and highlighted prompts using ANSI escape sequences.

---

Project Structure

| File | Description |
| :--- | :--- |
| `student.h` | Structure definitions, ANSI color macros, and function prototypes |
| `stud_main.c` | Main menu loop, user input handling, and program entry point |
| `stud_add.c` | Dynamic node allocation and student record insertion |
| `stud_show.c` | Formatted tabular display of linked list records |
| `stud_mod.c` | Search and modification of existing student records |
| `stud_del.c` | Deletion by roll number, duplicate name resolution, and full list cleanup |
| `stud_save.c` | File I/O routines (`fscanf` / `fprintf`) for persisting records to `student.dat` |
| `Makefile` | Automated compilation with `gcc -Wall -Wextra` |


---Build & Run---

1. Compile the project:
   ```bash
   make

2.  Run : 
   ./student.

4.  clean make : 
    rm -f *.o

    
------Thank you------:

:w
