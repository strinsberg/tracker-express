# Aegir Rest Service 3720

3720 group project.

#### Release
End of Sprint 1
**Version** 1.1

* Issues page
* Add issue form
* Submit test issues and view all issues

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
  3. You can view the add issue form. Submitting an issue currently only adds a test issue (does not use values in the form).
  4. Refreshing the issue page will update the list of issues.


# Contribution Guidlines

1. Master branch will always contain the current release. The only updates that will be made to this branch are merges with the dev branch or merges with urgent bug fixes.

2. To add a feature or Bug fix in general create a new branch from the dev branch. Make your changes and then submit a pull request to the dev branch.

3. If an urgent bug fix must be added to the release version create a new branch from the master branch. When the fix is complete submit a pull request for master branch. If everything goes according to plan this should not be necessary.

4. No pull requests should be submitted for branches that do not pass the pipline.

5. All code **must** follow a **TDD** process. To ensure this it is best to commit changes after writing the test. Then implementing the functionality and commiting again when the test is passing. If tests and implementation are really small this can be relaxed a bit.
