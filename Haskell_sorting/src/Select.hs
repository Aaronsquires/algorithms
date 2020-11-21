module Select (
    selection_Sort
) where

import Data.List (delete)

-- Selection Sort
-- Original Selection Sort -- Unfactored
-- selection_Sort :: Ord a => [a] -> [a]
-- selection_Sort xs = select_smallest xs

-- -- gets the smallest element from the list
-- select_smallest :: Ord a => [a] -> [a]
-- select_smallest [] = []
-- select_smallest xs = x : select_smallest xs'
--   where
--     x = smallest (head xs) (tail xs)
--     xs' = remove x xs

-- -- finds the smallest element in the list and sets to x
-- smallest :: Ord a => a -> [a] -> a
-- smallest x [] = x
-- smallest x (y:ys) = smallest (min x y) ys

-- remove :: Eq a => a -> [a] -> [a]
-- remove x (y:ys) =
--   if x==y
--     then ys
--     else y : remove x ys

-- Refactored Selection sort
selection_Sort :: (Ord a) => [a] -> [a]
selection_Sort [] = []
selection_Sort xs = minVal : (selection_Sort newList)
  where minVal = minimum xs 
        newList = delete minVal xs