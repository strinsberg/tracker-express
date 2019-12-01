var params = new URLSearchParams(window.location.search);
var assignee = -1;
var creator = -1;

function convertStatus(status) {
    if (status == 0) {
        return "New";
    } else if (status == 1) {
        return "Assigned";
    } else if (status == 2) {
        return "Fixed";
    } else if (status == 3) {
        return "Won't Fix";
    } else {
        return "Error: Bad Status";
    }
}

function convertPriority(priority) {
    if (priority == 2) {
        return "Low";
    } else if (priority == 10) {
        return "High";
    } else {
        return priority;
    }
}

// Get the issue
fetch("http://localhost:1234/trackEx/issues?id=" + params.get("id"))
.then(response => {
    return response.json();
})
.then(data => {
    var iss = data.response;
    document.getElementById("title").innerHTML = iss.title;
    document.getElementById("description").innerHTML = "Description: ".bold() + iss.description;
    document.getElementById("status").innerHTML = "Status:   ".bold() + convertStatus(iss.status);
    document.getElementById("assignee").innerHTML = "Assignee: ".bold() + "Unassigned";
    document.getElementById("creator").innerHTML = "Creator: ".bold() + "Guest";
    document.getElementById("priority").innerHTML = "Priority: ".bold() + convertPriority(iss.priority);
    document.getElementById("tags").innerHTML = "Tags: ".bold() + iss.tags.join(", ");
    
    assignee = iss.assignee;
    creator = iss.creator;
}).then(function() {
    // Get the name for the assignee
    if (assignee != -1) {
        fetch("http://localhost:1234/trackEx/users?id=" + assignee)
        .then(response => {
            return response.json();
        })
        .then(data => {
            var user = data.response;
            document.getElementById("assignee").innerHTML = "Assignee: ".bold() + user.name;
        })
    }

    // Get the name of the creator
    if (creator != -1) {
        fetch("http://localhost:1234/trackEx/users?id=" + creator)
        .then(response => {
            return response.json();
        })
        .then(data => {
            var user = data.response;
            document.getElementById("creator").innerHTML = "Creator: ".bold() + user.name;
        })
    }
}).catch(err => {
    console.error("Error:", err);
});

// Get all the comments
fetch("http://localhost:1234/trackEx/comments?issue=" + params.get("id"))
.then(response => {
    console.log(response);
    return response.json();
})
.then(data => {
    var table = document.getElementById("comment_table");
    data.response.forEach(com => {
        var row = table.insertRow(-1);
        
        var user = row.insertCell(0);
        var text = row.insertCell(1);
        var edit = row.insertCell(2)
        var del = row.insertCell(3);
        
        user.innerHTML = com.user_id;
        text.innerHTML = com.text;
        edit.innerHTML = '<a href="javascript:void(0);" onclick="editComment(' + com.id + ');">edit</a>';
        del.innerHTML = '<a href="javascript:void(0);" onclick="deleteComment(' + com.id + ');">delete</a>';

        console.log("Comment:", com);
    });
}).catch(err => {
    console.error("Error:", err);
});




// Functions //////////////////////////////////////////////////////////////////
function editIssue() {
    window.open("addIssue.html?id=" + params.get("id"), "_self");
}


async function deleteIssue() {
    if (confirm("Are you sure you would like to delete this issue?")) {
        const response = await fetch("http://localhost:1234/trackEx/issues?id=" + params.get("id") + "&delete")
        console.log(response);
        window.open("issues.html","_self");
    }
}

function addComment() {
    window.open("addComment.html?issue=" + params.get("id"), "_self");
}

async function editComment(id) {
    fetch('http://localhost:1234/trackEx/comments?id=' + id)
    .then(response => {
        return response.json();
    })
    .then(data => {
        comment = data.response;
        window.open("addComment.html?issue=" + params.get("id") + "&id=" + comment.id + "&user=" + comment.user_id,"_self");
    }).catch(err => {
        console.error("Error:", err);
    });
}

async function deleteComment(id) {
    if (confirm("Are you sure you would like to delete this comment?")) {
        const response = await fetch('http://localhost:1234/trackEx/comments?id=' + id + '&delete');
        console.log(response);
        window.open("singleIssue.html?id=" + params.get("id"),"_self");
    }
}
