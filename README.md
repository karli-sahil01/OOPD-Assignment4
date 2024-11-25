# OOPD Assignment 4: Research Publication Management System

This project focuses on managing research publications using Object-Oriented Programming (OOP) techniques. The system is divided into three main components:

## 1. Data Structure Design
### Objective
Design a data structure to hold essential details about a research publication. The following attributes are required:

- **Title**: The name of the publication.
- **Venue**: The journal or conference where the work was published.
- **Authors**: A list of authors with their names and affiliations.
- **DOI (Optional)**: The Digital Object Identifier for the publication.
- **Year**: The year the publication was made available.

### Additional Condition
At least one author must be affiliated with **"IIIT-Delhi"** as a mandatory requirement.

---

## 2. File Parsing and Validation
### Objective
Develop a program that processes a `.bib` file and transforms it into the publication structure. The program should also perform the following validation checks:

- **Formatting Checks**: Ensure the correct use of braces, commas, and other syntax elements in the `.bib` file.
- **Duplicate Authors**: Ensure no author is listed multiple times within the same publication.
- **Affiliation Verification**: Confirm that at least one author is affiliated with **"IIIT-Delhi"** by cross-referencing with a separate `affiliation.csv` file.

### Validation Steps:
1. Parse the `.bib` file and extract the publication details.
2. Perform syntax validation on the file.
3. Check for duplicate authors within each publication.
4. Use the `affiliation.csv` file to verify that the author affiliations are valid and that at least one author is associated with **"IIIT-Delhi"**.

---

## 3. Querying and Analysis
### Objective
Implement a query system with the following functionalities:

- **Author Search**: Allow users to input one or more author names and retrieve the publications associated with them.
- **Co-Author Analysis**: Compute the average number of co-authors for each queried author and display this along with the list of publications they have authored.

This project integrates file parsing, data validation, and statistical analysis within an Object-Oriented framework, providing a comprehensive tool for managing and analyzing academic publications.

---
## Usage
1. Place the `.bib` file containing publication data in the `data/` folder.
2. Ensure the `affiliation.csv` file is available to validate author affiliations.
3. Run the main script:
    ```bash
    python main.py
    ```
4. Follow the prompts to search for authors or perform co-author analysis.
