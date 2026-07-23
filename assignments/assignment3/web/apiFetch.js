if (window.Worker) {
    const apiWorker = new Worker('webWorker.js');

    apiWorker.onmessage = function(e) {
        const response = e.data;

        if (response.error) {
            console.error('Error:', response.error);
        }
        else if (response.success && response.data) {
            response.data.forEach(userString => {
                console.log(userString);
            });
        }
    };

    apiWorker.onerror = function(err) {
        console.error('Worker encountered an error', err.message);
    };

    apiWorker.postMessage('start_fetch');
}
else {
    console.error('Web Worker Error');
}