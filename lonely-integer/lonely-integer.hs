import Control.Monad
import Data.List

lonelyIntegerRec :: [Int] -> Int
lonelyIntegerRec [] = 0
lonelyIntegerRec [x] = x
lonelyIntegerRec (x:y:xs) | x == y = lonelyIntegerRec xs
						  | x /= y = x

lonelyInteger :: [Int] -> Int
lonelyInteger xs = lonelyIntegerRec (sort xs)

main :: IO ()
main = do
  n <- readLn :: IO Int
  line <- getLine
  let numbers = map read (words line)
  let ans = lonelyInteger numbers
  print ans
