open System

let factorial n = [1.0 .. n] |> List.fold (*) 1.0

let exp x = [0.0 .. 9.0] |> List.map (fun y -> (x ** y) / (factorial y)) |> List.sum

let processNumber () =
    let x = Console.ReadLine() |> float
    printfn "%.4f" (exp x)
    

[<EntryPoint>]
let main argv =
    let n = Console.ReadLine() |> int
    for i in [1..n] do
        processNumber ()
    0