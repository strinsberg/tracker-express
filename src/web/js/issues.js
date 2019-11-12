fetch("http://localhost:1234/trackEx/issues") 
    .then(response => {
    console.log(response);
    return response.json();
    })
    .then(data => {
        var table = document.getElementById("issue_table");
        data.response.forEach(issue => {
            var iss = JSON.parse(issue)
            var row = table.insertRow(-1);
            
            var title = row.insertCell(0);
            var create = row.insertCell(1);
            var prior = row.insertCell(2);
            
            title.innerHTML = iss.title;
            create.innerHTML = iss.creator;
            prior.innerHTML = iss.priority;
        })
    })
    .catch(err => {
    console.error("Error:", err);
});
