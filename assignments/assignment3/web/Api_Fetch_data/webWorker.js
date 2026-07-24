self.onmessage = function(e) {
    if (e.data === 'start_fetch') {
        const xhr = new XMLHttpRequest();
        xhr.open('GET', 'https://jsonplaceholder.typicode.com/users', true);

        xhr.onload = function() {
            if (xhr.status >= 200 && xhr.status < 300) {
                try {
                    const users = JSON.parse(xhr.responseText);

                    if (!users || !Array.isArray(users) || users.length === 0) {
                        self.postMessage({error: "No users found from the API"});
                        return;
                    }

                    const formattedUsers = users.map(user => {
                        const status = user.active ? 'Active' : 'Inactive';
                        return `${user.name} - ${status}`;
                    });
                    
                    self.postMessage({success:true, data: formattedUsers});
                } catch (parseError) {
                    self.postMessage({error: 'Failed to parse JSON response'});
                }
                
            }
            else {
                self.postMessage({error: `API request failed with status: ${xhr.status}`});
            }
        };

        xhr.onerror = function() {
            self.postMessage({error: 'A network error occurred while fetching data'});
        };
        xhr.send();
    }
};