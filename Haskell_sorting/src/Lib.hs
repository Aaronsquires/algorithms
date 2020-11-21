-- Aaron Squires, N0748944
-- Functional Test Driven Development
-- Haskell Assignment 2
-- Prime Numbers, Quick Sort, Merge Sort, Bubble Sort

module Lib (
    quick_sort,
    bubble_sort,
    selection_Sort,
    merge_sort
) where

import Data.List (delete)

-- Selection Sort
selection_Sort :: (Ord a) => [a] -> [a]
selection_Sort [] = []
selection_Sort xs = minVal : (selection_Sort newList)
  where minVal = minimum xs 
        newList = delete minVal xs

-- Quick Sort   
quick_sort :: Ord a => [a] -> [a]
quick_sort list = quick_sort' list []
  where
  quick_sort' [] a = a
  quick_sort' (x:xs) a = quick_sort'
    [smallest | smallest <- xs, smallest <= x]
    (x : (quick_sort' [largest | largest <- xs, largest > x] a))

-- Bubble Sort
bubble_sort :: (Ord a) => [a] -> [a]
bubble_sort [] = []
bubble_sort xs = iterate swap xs !! (length xs - 1)
    where
        swap [x] = [x]
        swap (x:y:zs)
            |x > y     = y : swap (x:zs)
            |otherwise = x : swap (y:zs)

-- Merge Sort
merge_sort :: Ord a => [a] -> [a] -> [a]
merge_sort [x] = [x]
merge_sort l =
  merge (merge_sort left) (merge_sort right)
    where
      left = take' (length' l `div` 2) l
      right = drop' (length' l `div` 2) l