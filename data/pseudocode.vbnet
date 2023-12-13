//!! insertionSort
procedure insertionSort
   i_a   : array of char

   c     : integer
   count : integer
   i     : integer
   j     : integer

   c = 0
   count = size of i_a

   for i = 0 to count - 1
      for j = i to 1 step -1
         c = c + 1
         if i_a[j] > i_a[j - 1] then
            exit loop
         else
            swap i_a[j] and i_a[j - 1]
         end if
      end for
   end for

   return c
end procedure


//!! selectionSort
procedure selectionSort
   i_a   : array of char

   c     : integer
   count : integer
   i     : integer
   j     : integer
   min_i : integer

   c = 0
   count = size of i_a
   min_i = 0

   for i = 0 to count - 2
      min_i = i
      for j = i + 1 to count - 1
         if i_a[j] < i_a[min_i] then
            min_i = j
         end if
      end for
      c = c + 1
      swap i_a[min_i] and i_a[i]
   end for

   return c
end procedure


//!!shellSort
procedure shellSort
   i_a   : array of char

   c     : integer
   count : integer
   gap   : integer
   i     : integer
   k     : integer

   c = 0
   count = size of i_a
   gap = count / 2

   while gap > 0
      for i = gap to count - 1
         for k = i to gap step -gap
            if i_a[k - gap] > i_a[k] then
               c = c + 1
               swap i_a[k] and i_a[k - gap]
            end if
         end for
      end for
      gap = gap / 2
   end while

   return c
end procedure


//!! mergeSort
procedure mergeSort
   whole  : array of char
   
   if size of whole is 1
      return whole
   else
      left = slice of whole from 0 to size of whole / 2
      right = slice of whole from size of whole / 2 to end

      left = mergeSort(left)
      right = mergeSort(right)

      merge(left, right, whole)

      return whole
   end if
end procedure

procedure merge
   left   : array of char
   right  : array of char
   result : array of char

   x      : integer
   y      : integer
   k      : integer

   x = 0
   y = 0
   k = 0

   while x < size of left and y < size of right
      if left[x] < right[y] then
         result[k] = left[x]
         x = x + 1
      else
         result[k] = right[y]
         y = y + 1
      end if
      k = k + 1
   end while

   rest = empty array of char
   restIndex = 0

   if x >= size of left then
      rest = right
      restIndex = y
   else
      rest = left
      restIndex = x
   end if

   for i = restIndex to size of rest - 1
      result[k] = rest[i]
      k = k + 1
   end for
end procedure



//!! mergeSort3
procedure mergeSort
   liste : array of char
   
   return sort(liste, 1, size of liste)
end procedure

procedure sort
   liste : array of char
   start : integer
   end   : integer
   
   if end - start < 1
      return liste
   else
      mid1 = start + ((end - start) / 3)
      mid2 = start + 2 * ((end - start) / 3)

      sort(liste, start, mid1)
      sort(liste, mid1 + 1, mid2)
      sort(liste, mid2 + 1, end)
      merge(liste, start, mid1, mid2, end)

      return liste
   end if
end procedure

procedure merge
   liste : array of char
   s     : integer
   mid1  : integer
   mid2  : integer
   end   : integer

   left_array  : array of char
   mid_array   : array of char
   right_array : array of char

   ind_left    : integer
   ind_mid     : integer
   ind_right   : integer

   left_array = slice of liste from s to mid1 + 1
   mid_array = slice of liste from mid1 + 1 to mid2 + 1
   right_array = slice of liste from mid2 + 1 to end + 1

   left_array.push_back(CHAR_MAX)
   mid_array.push_back(CHAR_MAX)
   right_array.push_back(CHAR_MAX)

   ind_left = 0
   ind_mid = 0
   ind_right = 0

   for i = s to end
      c = c + 1
      minimum = min(min(left_array[ind_left], mid_array[ind_mid]), right_array[ind_right])
      if minimum == left_array[ind_left]
         liste[i] = left_array[ind_left]
         ind_left = ind_left + 1
      else if minimum == mid_array[ind_mid]
         liste[i] = mid_array[ind_mid]
         ind_mid = ind_mid + 1
      else
         liste[i] = right_array[ind_right]
         ind_right = ind_right + 1
      end if
   end for
end procedure



//!! quickSort
procedure quickSort
   liste   : array of char
   isHoare : boolean
   
   c = 0
   if isHoare
      quickSortHoare(liste, 0, size of liste - 1)
   else
      quickSortLomuto(liste, 0, size of liste - 1)
end procedure

procedure quickSortHoare
   liste : array of char
   low   : integer
   high  : integer

   if low < high
      pi = partitionHoare(liste, low, high)
      quickSortHoare(liste, low, pi)
      quickSortHoare(liste, pi + 1, high)
   end if
end procedure

procedure quickSortLomuto
   liste : array of char
   low   : integer
   high  : integer

   if low < high
      pi = partitionLomuto(liste, low, high)
      quickSortLomuto(liste, low, pi - 1)
      quickSortLomuto(liste, pi + 1, high)
   end if
end procedure

function partitionHoare
   liste : array of char
   low   : integer
   high  : integer

   pivot = liste[low]
   i = low - 1
   j = high + 1

   while true
      repeat
         c = c + 1
         i = i + 1
      until liste[i] >= pivot

      repeat
         j = j - 1
      until liste[j] <= pivot

      if i >= j
         return j

      swap liste[i] and liste[j]
   end while
end function

function partitionLomuto
   liste : array of char
   low   : integer
   high  : integer

   pivot = liste[high]
   i = low - 1

   for j = low to high - 1
      c = c + 1
      if liste[j] <= pivot
         i = i + 1
         swap liste[i] and liste[j]
      end if
   end for

   swap liste[i + 1] and liste[high]
   return i + 1
end function


//!! heapSort
procedure heapify
   liste : array of char
   N     : integer
   i     : integer

   c = c + 1
   largest = i
   l = 2 * i + 1
   r = 2 * i + 2

   if l < N and liste[l] > liste[largest]
      largest = l

   if r < N and liste[r] > liste[largest]
      largest = r

   if largest is not equal to i
      swap liste[i] and liste[largest]
      heapify(liste, N, largest)
   end if
end procedure

procedure heapSort
   liste : array of char

   s = size of liste

   for i = s / 2 - 1 down to 0
      heapify(liste, s, i)

   for i = s - 1 down to 1
      swap liste[0] and liste[i]
      heapify(liste, i, 0)
   end for
end procedure
