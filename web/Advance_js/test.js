const promise = new Promise((resolve, reject) => {
    if (true) {
        resolve('Stuff worked')
    } else {
        reject('Error, it broke')
    }
})

promise.then(result => result + '!').then(result2 =>
        result2 + '!').then(result3 => {console.log(result3);})
    .catch(() => console.log('error!'));
    