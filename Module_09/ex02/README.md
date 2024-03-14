## Ford-Johnson Algorithm

The Ford-Johnson algorithm, also known as merge-insertion sort, is an 3-step sorting algorithm designed to perform as few comparisons as possible to sort a collection.

Example:
``794 387 43 306 7654 18 1`` 

**Step 1**: Split the collection in n/2 pairs of 2 elements and order these elements pairwise. If the number of elements is odd, the last element of the collection isn't paired with any element. Imagine that your collection is divided in pairs of elements. Sorting every pair of the collection. If the number of elements (N) is odd, the last number wont be sorted.

``387 794 43 306 418 765 1``

**Step 2**: Recursively sort the pairs of elements by their highest value. If the number of elements is odd, the last element is not considered a highest value and is left at the end of the collection (an easy implementation is to remove the last element if its odd, execute step 2 and then insert it as the last element). Consider that the highest values form a sorted list that we will call the main chain ``a``. The rest of the elements will be known as pend elements ``b`` - smaller values + last odd number (if it is the case).

For every ``k``, we have that b<sub>k</sub> < a<sub>k</sub>

``43 306 418 765 387 794 ``

a = {306, 765, 794}

b = {43, 418, 387, 1}

**Step 3**: Insert the pend elements into the main chain, following a certain order. Meaning, the elements of the collection b are not inserter in the main chaine a by the natural order (index = 0, 1, 2, ...). The index of the next element to insert is giving by the jacobsthal sequence.

``1 43 306 387 418 765 794``

[to be finished by the end of Mar 2024]

### Important topics

- **Binary Search**

- **Jacobsthal sequence**

### References

- https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
