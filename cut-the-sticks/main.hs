import Control.Monad
import Data.List

cutTheSticks :: [Int] -> [Int]
cutTheSticks [] = []
cutTheSticks (x:xs) = (1 + length xs) : cutTheSticks (dropWhile (== x) xs)

printSequence :: [Int] -> IO ()
printSequence xs = mapM_ print xs

main :: IO ()
main = do
  n <- readLn :: IO Int
  line <- getLine
  let numbers = map read (words line)
  let ans = cutTheSticks (sort numbers)
  printSequence ans