let arr=  { one: 1, two: 2, three: 3};
for (let prop in arr) {
  if (arr.hasOwnProperty(prop)) {
    console.log(prop )
  }
}
for (let prop in arr) {
  if (arr.hasOwnProperty(prop)) {
    console.log(arr[prop])
  }
}
