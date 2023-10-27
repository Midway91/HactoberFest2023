// TypeScript program to implement the Shell Sort on ascending order.

const shellSort = (arr: number[]): number[] => {
  const n = arr.length;
  let gap = Math.floor(n / 2);

  while (gap > 0) {
    for (let i = gap; i < n; i++) {
      const temp = arr[i];
      let j = i;

      while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        j -= gap;
      }

      arr[j] = temp;
    }

    gap = Math.floor(gap / 2);
  }

  return arr;
};


const unsortedArray = [12, 34, 11, 9, 3, 45, 23, 18];
const sortedArray = shellSort(unsortedArray);
console.log("Sorted Array:", sortedArray);
