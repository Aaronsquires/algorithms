module Prime where

import Data.Foldable     (for_)
import Test.Hspec        (Spec, describe, it, shouldBe)
import Test.Hspec.Runner (configFastFail, defaultConfig, hspecWith)

import Primes (primeFactors)

main :: IO ()
main = hspecWith defaultConfig {configFastFail = True} specs

specs :: Spec
specs = describe "Prime Factor Tests" $ for_ cases test
  where

    test (description, n, expected) = it description assertion
      where
        assertion   = primeFactors n `shouldBe` expected

    cases = [ ("no factors",                              1,                 [] )
            , ("prime number"st,                            2,                [2] )
            , ("square of a prime",                       9,             [3, 3] )
            , ("cube of a prime",                         8,          [2, 2, 2] )
            , ("product of primes and non-primes",       12,          [2, 2, 3] )
            , ("product of primes",                  901255,   [5, 17, 23, 461] )
            , ("factors include a large prime", 93819012551, [11, 9539, 894119] ) ]