window.onload = function() {
    getIssues("http://localhost:1234/trackEx/issues");
}

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

function filterIssues() {
    var priority = document.getElementById("priority-filter");
    var tag = document.getElementById("tag-filter");
    var status = document.getElementById("status-filter");
    
    
    var url = "http://localhost:1234/trackEx/issues?filter";
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

    getIssues(url);
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
            if (data.response != null) {
            
                data.response.forEach(issue => {
                    var iss = issue
                    console.log(iss);
                    var row = newBody.insertRow(-1);
                    
                    var title = row.insertCell(0);
                    var create = row.insertCell(1);
                    var prior = row.insertCell(2);
                    
                    title.innerHTML = '<a href="singleIssue.html?id=' + iss.id + '">' + iss.title + '</a>';
                    create.innerHTML = convertStatus(iss.status);
                    prior.innerHTML = convertPriority(iss.priority);
                })
            }
            table.replaceChild(newBody, body);
        })
        .catch(err => {
        console.error("Error:", err);
    });
}
