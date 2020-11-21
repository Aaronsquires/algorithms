module Merge (merge_sort) where

-- Merge Sort
merge_sort :: Ord a => [a] -> [a] -> [a]
merge_sort [x] = [x]
merge_sort l =
  merge (merge_sort left) (merge_sort right)
    where
      left = take' (length' l `div` 2) l
      right = drop' (length' l `div` 2) l