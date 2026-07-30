const fields = [ 
  "First Name", 
  "Last Name", 
  "Email"
]; 

function generateForm() {
    return fields.map(field => 
        `<label>${field}</label>\n 
        <input type='text'>`
    ).join('\n');
}

console.log(generateForm());