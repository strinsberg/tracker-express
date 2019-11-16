# Aegir Rest Service 3720

3720 group project.

#### Release
End of Sprint 2
**Version** 1.2

* Single Issue, User pages
* Add issue, users forms
* Submit custom form data for Issues and Users
* List all Issues and Users
* Forms return to previous pages and refresh lists

#### Documentation
* Project release documentation is in docs folder
* Code documentation using doxygen is in docs/source
* All design, planning, and team documentation is in docs/planning

#### Members
Lorenzo Conrad (Front-End Specialist)  
Mathew Richards (Idea Specialist)  
Steven Deutekom (Scrum Master)  


# Compilation and Use

* Compile and run the tests `$ make testTrackEx`
* Compile the server `$ make trackEx`
* Run the server `$ ./trackEx`
* To see some basic initial functionality
  1. open `$ src/web/index.html` in your browser.
  2. Open issues page to see the current issue list (which is empty when the server starts).
  3. You can add custom issues.
  4. Refreshing the issue page will update the list of issues.
  5. Selecting the issue title will bring up a page for just that issue.
  6. Users page will work same as Issues.


# Contribution Guidlines

1. Master branch will always contain the current release. The only updates that will be made to this branch are merges with the dev branch or merges with urgent bug fixes.

2. To add a feature or Bug fix in general create a new branch from the dev branch. Make your changes and then submit a pull request to the dev branch.

3. If an urgent bug fix must be added to the release version create a new branch from the master branch. When the fix is complete submit a pull request for master branch. If everything goes according to plan this should not be necessary.

4. No pull requests should be submitted for branches that do not pass the pipline.

5. All code should follow a **TDD** process if at all possible. Try your best. If you don't have full tests plan on writing them before moving on to new features.
