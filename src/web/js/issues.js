window.onload = function() {
    getIssues("http://localhost:1234/trackEx/issues");
}

function filterIssues() {
    var priority = document.getElementById("priority-filter");
    var tag = document.getElementById("tag-filter");
    var status = document.getElementById("status-filter");
    
    
    var url = "http://localhost:1234/trackEx/issues";
    if (status.value != -1) {
        url += "&status=" + status.value;
    }
    
    if (priority.value >= 0) {
        url += "&priority=" + priority.value;
    }
    
    if (tag.value != "") {
        url+= "&tag=" + tag.value;
    }
    
    console.log(url);
    
    // Uncomment this when the filter function is working on the server
    //getIssues(url);
}

function getIssues(url) {
    fetch(url) 
        .then(response => {
        console.log(response);
        return response.json();
        })
        .then(data => {
            var table = document.getElementById("issue_table");
            var body = document.getElementById("table_body");
            var newBody = document.createElement("tbody");
            newBody.id = "table_body";
            data.response.forEach(issue => {
                var iss = JSON.parse(issue)
                var row = newBody.insertRow(-1);
                
                var title = row.insertCell(0);
                var create = row.insertCell(1);
                var prior = row.insertCell(2);
                
                title.innerHTML = '<a href="singleIssue.html?id=' + iss.id + '">' + iss.title + '</a>';
                create.innerHTML = iss.creator;
                prior.innerHTML = iss.priority;
            })
            table.replaceChild(newBody, body);
        })
        .catch(err => {
        console.error("Error:", err);
    });
}
