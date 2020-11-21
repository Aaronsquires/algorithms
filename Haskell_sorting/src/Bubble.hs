module Bubble (
    bubble_sort
) where

-- Bubble Sort
bubble_sort :: (Ord a) => [a] -> [a]
bubble_sort [] = []
bubble_sort xs = iterate swap xs !! (length xs - 1)
    where
        swap [x] = [x]
        swap (x:y:zs)
            |x > y     = y : swap (x:zs)
            |otherwise = x : swap (y:zs)