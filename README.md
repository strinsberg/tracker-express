# Aegir Rest Service 3720

3720 group project.

#### Release
Proposal Phase
**Version** 1.0

#### Documentation
* Project release documentation is in docs folder
* Agile documentation is in docs/agile, with finalized sprint retrospectives in docs
* Code documentation using doxygen is in docs/source
* All design, planning, and team documentation is in docs/planning

#### Members
Lorenzo Conrad (Front-End Specialist)  
Mathew Richards (Idea Specialist)  
Steven Deutekom (Scrum Master)  

# Contribution Guidlines

1. Master branch will always contain the current release. The only updates that will be made to this branch are merges with the dev branch or merges with urgent bug fixes.

2. To add a feature or Bug fix in general create a new branch from the dev branch. Make your changes and then submit a pull request to the dev branch.

3. If an urgent bug fix must be added to the release version create a new branch from the master branch. When the fix is complete submit a pull request for master branch. If everything goes according to plan this should not be necessary.

4. No pull requests should be submitted for branches that do not pass the pipline.

5. All code **must** follow a **TDD** process. To ensure this it is best to commit changes after writing the test. Then implementing the functionality and commiting again when the test is passing. If tests and implementation are really small this can be relaxed a bit.
