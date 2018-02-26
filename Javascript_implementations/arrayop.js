let arr=[1,4,2,5,3];
let sum=0;
for(let index=0;index<arr.length;index++)
{
  sum=sum+arr[index];
}
console.log(`Sum is following for the given array${sum}`);
let end=arr.length-1;
let start=0;
while(start<end)
{
  [arr[start],arr[end]]=[arr[end],arr[start]];
  start++;
  end--;
}
console.log(arr);
console.log('Simple Sort is below');
arr.sort();
console.log(arr);
