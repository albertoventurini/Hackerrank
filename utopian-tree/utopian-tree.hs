import Control.Monad

summer :: Int -> Int -> Int
summer a 0 = a
summer a n = spring (a+1) (n-1)

spring :: Int -> Int -> Int
spring a 0 = a
spring a n = summer (a*2) (n - 1)

processLine :: String -> Int
processLine l = spring 1 (read l)

main :: IO ()
main = do
  n <- readLn
  lines <- replicateM n getLine
  let ans = map processLine lines
  mapM_ print ans
