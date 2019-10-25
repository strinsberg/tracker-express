fetch("http://localhost:1234/trackEx/issues") 
.then(response => {
console.log(response);
return response.json();
})
.then(data => {
console.log("Success:", JSON.stringify(data));
})
.catch(err => {
console.error("Error:", err);
});
