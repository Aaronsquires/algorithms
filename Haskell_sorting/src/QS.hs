module QS (quick_sort) where

-- Quick Sort   
quick_sort :: Ord a => [a] -> [a]
quick_sort list = quick_sort' list []
  where
  quick_sort' [] a = a
  quick_sort' (x:xs) a = quick_sort'
    [smallest | smallest <- xs, smallest <= x]
    (x : (quick_sort' [largest | largest <- xs, largest > x] a))