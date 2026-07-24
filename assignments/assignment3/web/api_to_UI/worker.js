self.onmessage = function(event) {
    if (event.data === 'FETCH_USERS') {
        const xhr = new XMLHttpRequest();
        xhr.open('GET', 'https://jsonplaceholder.typicode.com/users', true);

        xhr.onload = function() {
            if (xhr.status >= 200 && xhr.status < 300) {
                try {
                    const users = JSON.parse(xhr.responseText);
                    if(Array.isArray(users) && users.length > 0) {
                        self.postMessage({success: true, data: users});
                    }
                    else {
                        self.postMessage({success: true, data: []});
                    }
                } catch (error) {
                    self.postMessage({success: false, error: 'Json parsing failed'});
                }
            } else {
                self.postMessage({success: false, error: 'API returned an error'});
            }
        };

        xhr.onerror = function() {
            self.postMessage({success: false, error: 'Network error occurred'});
        }

        xhr.send();
    }
};