import Data.Foldable     (for_)
import Test.Hspec        (Spec, describe, it, shouldBe)
import Test.Hspec.Runner (configFastFail, defaultConfig, hspecWith)

import Lib (quick_sort)
import Select (selection_Sort)
import Bubble (bubble_sort)
import QS (quick_sort)
import Merge (merge_sort)

main :: IO ()
main = hspecWith defaultConfig {configFastFail = True} specs

specs :: Spec
specs = describe "Test Sorting List" $ for_ sortCases test
  where

    test (description, n, expected) = it description assertion
      where
          assertion =  quick_sort n `shouldBe` expected

    sortCases = [
        ("Testing Empty List", [], []),
        ("Testing One Item", [1], [1]),
        ("Testing Sorted List", [1, 2, 3, 4, 10], [1, 2, 3, 4, 10]),
        ("Testing Not Sorted List", [1, 9, 5, 27, 26, 21, 15, 4], [1, 4, 5, 9, 15, 21, 26, 27])]
