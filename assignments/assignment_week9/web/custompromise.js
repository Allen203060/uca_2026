function NewPromise(executor) {
    this.state = "pending";
    this.value = undefined;
    this.reason = undefined;
    this.onFulfilledCallbacks = [];
    this.onRejectedCallbacks = [];

    const resolve = (value) => {
        if (this.state === "pending") {
            this.state = "fulfilled";
            this.value = value;
            this.onFulfilledCallbacks.forEach(fn => fn());
        }
    };

    const reject = (reason) => {
        if (this.state === "pending") {
            this.state = "rejected";
            this.reason = reason;
            this.onRejectedCallbacks.forEach(fn => fn());
        }
    };

    try {
        executor(resolve, reject);
    } catch (err) {
        reject(err);
    }
}

NewPromise.prototype.then = function (onFulfilled, onRejected) {
    onFulfilled = typeof onFulfilled === "function" ? onFulfilled : v => v;
    onRejected = typeof onRejected === "function" ? onRejected : err => { throw err };

    const promise2 = new NewPromise((resolve, reject) => {

        if (this.state === "fulfilled") {
            setTimeout(() => {
                try {
                    const x = onFulfilled(this.value);
                    resolvePromise(promise2, x, resolve, reject);
                } catch (err) {
                    reject(err);
                }
            });
        }

        if (this.state === "rejected") {
            setTimeout(() => {
                try {
                    const x = onRejected(this.reason);
                    resolvePromise(promise2, x, resolve, reject);
                } catch (err) {
                    reject(err);
                }
            });
        }

        if (this.state === "pending") {
            this.onFulfilledCallbacks.push(() => {
                setTimeout(() => {
                    try {
                        const x = onFulfilled(this.value);
                        resolvePromise(promise2, x, resolve, reject);
                    } catch (err) {
                        reject(err);
                    }
                });
            });

            this.onRejectedCallbacks.push(() => {
                setTimeout(() => {
                    try {
                        const x = onRejected(this.reason);
                        resolvePromise(promise2, x, resolve, reject);
                    } catch (err) {
                        reject(err);
                    }
                });
            });
        }
    });

    return promise2;
};

NewPromise.prototype.catch = function (onRejected) {
    return this.then(null, onRejected);
};

function resolvePromise(promise2, x, resolve, reject) {
    if (promise2 === x) {
        return reject(new TypeError("Chaining cycle detected"));
    }

    if (x instanceof NewPromise) {
        x.then(resolve, reject);
    } else {
        resolve(x);
    }
}