import requests
import json

# urls
base_url = "http://localhost:1234/trackEx"
issue_url = base_url + "/issues"
user_url = base_url + "/users"
comments_url = base_url + "/comments"


## ISSUES ######################################################

# add a couple of issues
body1 = {
    "title": "issue 1",
    "description": "a test issue",
    "priority": 20,
    "assignee": 2,
    "creator": 1,
    "status": 1,
    "tags": ["minor"],
}

body2 = {
    "title": "issue 2",
    "description": "another test issue",
    "priority": 10,
    "assignee": 1,
    "creator": 2,
    "status": 1,
    "tags": ["OS", "Critical"],
}

r_add1 = requests.post(issue_url, data = json.dumps(body1))
r_add2 = requests.post(issue_url, data = json.dumps(body2))

# get all issues
r_all_issues = requests.get(issue_url)

# filter issues
#r_p_filt = requests.get(issue_url + "?priority=20")
#r_s_filt = requests.get(issue_url + "?status=1")
#r_t_filt = requests.get(issue_url + "?tag=OS")

# get a single issue
r_single_issue = requests.get(issue_url + "?id=1")

# get an issue with invalid ID
r_invalid_issue = requests.get(issue_url + "?id=20")

# delete an issue
r_delete_issue = requests.get(issue_url + "?id=2&delete");
r_all_issues = requests.get(issue_url)

# update an issue
r_update_issue = requests.post(issue_url + "?id=1", data = json.dumps(body2));

## USERS #######################################################

# add a couple of users
body3 = {
    "name": "Lorenzo",
    "blurb": "Web master",
    "pic": 3,
}

body4 = {
    "name": "Mathew",
    "blurb": "Design specialist",
    "pic": 1,
}

r_add3 = requests.post(user_url, data = json.dumps(body3))
r_add4 = requests.post(user_url, data = json.dumps(body4))

# get all users
r_all_users = requests.get(user_url)

# get a single user 
r_single_user = requests.get(user_url + "?id=1")

# get an user with invalid ID
r_invalid_user = requests.get(user_url + "?id=20")

# delete an user
r_delete_user = requests.get(user_url + "?id=2&delete");
r_all_user = requests.get(user_url)

# update user
r_update_user = requests.post(user_url + "?id=1", data = json.dumps(body4));


## Comments ####################################################

# create some comments
body5 = {
    "issue_id": 1,
    "user_id": 1,
    "text": "I don't think this Issue is necessary.",
}

body6 = {
    "issue_id": 1,
    "user_id": 1,
    "text": "Why have we not deleted this yet",
}

r_comment1 = requests.post(comments_url, json.dumps(body5))
r_comment2 = requests.post(comments_url, json.dumps(body6))

# get all comments
r_all_comments = requests.get(comments_url);

# get a comment
r_single_comment = requests.get(comments_url + "?id=1")

# get an invalid comment
r_invalid_comment = requests.get(comments_url + "id?=20")

# delete a comment
r_delete_comment = requests.get(comments_url + "?id=2&delete")
r_all_comments = requests.get(comments_url)

# update a comment
r_update_comment = requests.post(comments_url + "?id=1", json.dumps(body6))

