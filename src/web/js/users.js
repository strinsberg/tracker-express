fetch("http://localhost:1234/trackEx/users") 
    .then(response => {
    console.log(response);
    return response.json();
    })
    .then(data => {
        var table = document.getElementById("user_table");
        data.response.forEach(user_str => {
            var user = JSON.parse(user_str)
            var row = table.insertRow(-1);
            
            var id = row.insertCell(0);
            var name = row.insertCell(1);
            var pic = row.insertCell(2);
            
            id.innerHTML = user.id;
            name.innerHTML = user.name;
            pic.innerHTML = user.pic;
        })
    })
    .catch(err => {
    console.error("Error:", err);
});
