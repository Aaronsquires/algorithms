module Primes (
    primeFactors,
) where

-- Calculate the Prime Factors of a number
-- Test algorithm
primeFactors :: Int -> [Int]

primeFactors 1 = []
primeFactors 2 = [2]
primeFactors 3 = [3]

primeFactors n = divisor : primeFactors (n `div` divisor) where 
        divisor = head $ dropWhile (\x -> n `rem` x /= 0) [2..]
