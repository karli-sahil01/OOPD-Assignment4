### OOPD-Assignment 4: Research Publication Management
This project manages research publications using Object-Oriented Programming (OOP) principles. It is structured into three main sections:

### 1. Data Structure Implementation
### Goal
Design a data structure to encapsulate the essential details of a publication. The attributes are as follows:

Title: Represents the name of the research work.
Venue: Specifies the conference or journal where the research was published.
Authors: A list containing the names of the authors and their affiliations.
DOI (Optional): The Digital Object Identifier for the publication.
Year: The year the publication was released.
Additional Condition
At least one author must be affiliated with "IIIT-Delhi" to meet the assignment requirements.


### 2. File Parsing and Validation
### Objective
Develop a program to process a .bib file and convert its contents into the designed publication structure. The program should validate the file for the following:

Formatting Validation:

Ensure there are no issues with braces, commas, or the syntax of the .bib file.
Duplicate Authors:

Confirm that no author appears more than once in the same publication.
Affiliation Check:

Verify that at least one author is affiliated with "IIIT-Delhi". Use a separate faculty.csv file for matching names to affiliations.
Steps for Validation:
Parse the .bib file and populate the data structure.
Validate that the file's syntax is correct.
Check for duplicate author entries within individual publications.
Use the faculty.csv file to confirm that author affiliations are valid and ensure at least one author has the required affiliation.


### 3. Querying and Analysis
### Goal
Implement a query system with the following features:

Search by Author Names:

Accept one or more author names as input.
Retrieve and display the publications authored by the queried individuals.
Co-Author Analysis:

Compute the average number of co-authors for each queried author across their publications.
Display the results along with the list of publications.
This program combines file parsing, data validation, and statistical analysis using Object-Oriented Design, making it a versatile tool for managing and analyzing research publications.