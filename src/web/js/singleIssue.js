var params = new URLSearchParams(window.location.search);

fetch("http://localhost:1234/trackEx/issues?id=" + params.get("id"))
.then(response => {
    return response.json();
})
.then(data => {
    var iss = JSON.parse(data.response);
    document.getElementById("title").innerHTML = iss.title;
    document.getElementById("description").innerHTML = iss.description;
    document.getElementById("status").innerHTML = "Status: " + iss.status;
    document.getElementById("assignee").innerHTML = "Assignee: " + iss.assignee;
    document.getElementById("creator").innerHTML = "Creator: " + iss.creator;
    document.getElementById("priority").innerHTML = "Priority: " + iss.priority;
    document.getElementById("tags").innerHTML = "Tags: " + iss.tags;
});

fetch("http://localhost:1234/trackEx/comments?issue=" + params.get("id"))
.then(response => {
    console.log(response);
    return response.json();
})
.then(data => {
    var table = document.getElementById("comment_table");
    data.response.forEach(comment => {
        var com = JSON.parse(comment);
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
        comment = JSON.parse(data.response);
        window.open("addComment.html?issue=" + params.get("id") + "&id=" + comment.id + "&user=" + comment.user_id,"_self");
    }).catch(err => {
        console.error("Error:", err);
    });
}

async function deleteComment(id) {
    const response = await fetch('http://localhost:1234/trackEx/comments?id=' + id + '&delete');
    console.log(response);
    window.open("singleIssue.html?id=" + params.get("id"),"_self");
}
