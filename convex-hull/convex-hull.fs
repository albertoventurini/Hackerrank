open System

type Point = Point of float * float

//let distance (Point (x1, y1)) (Point (x2, y2)) =
let distance p1 p2 =
    let (Point (x1, y1)) = p1
    let (Point (x2, y2)) = p2
    sqrt ((x1 - x2) ** 2.0 + (y1 - y2) ** 2.0)

let angle p1 p2 p3 =
    let numerator = (distance p1 p2) ** 2.0 + (distance p1 p3) ** 2.0 - (distance p2 p3) ** 2.0
    let denominator = 2.0 * (distance p1 p2) * (distance p1 p3)
    Math.Acos (numerator / denominator)

let findNeighbors p points =
    let sortedNeighbors = List.sortBy (fun point -> distance p point) points |> Seq.take 4
    List.filter (fun x -> Seq.exists ((=) x) sortedNeighbors) points

let leftShift (x::xs) = xs @ [x]

let sumNeighborAngles p points =
    let neighbors = findNeighbors p points
    let pointPairs = List.zip neighbors (leftShift neighbors)
    let angles = List.map (fun (p1, p2) -> angle p p1 p2) pointPairs
    List.sum angles

let isInnerPoint p points =
    let sumAngles = sumNeighborAngles p points
    sumAngles >= 360.0 && sumAngles <= 360.0

let outerPoints points = List.filter (fun p -> not (isInnerPoint p points)) points

let perimeter points =
    List.zip points (leftShift points)
    |> List.map (fun (p1, p2) -> distance p1 p2)
    |> List.sum

let convexHullPerimeter points =
    match Seq.length points with
    | 3 | 4 -> perimeter points
    | _ -> perimeter (outerPoints points)
    //let outerP = outerPoints points
    
    //List.zip outerP (leftShift outerP)
    //|> List.map (fun (p1, p2) -> distance p1 p2)
    //|> List.sum

let readPoint ()  =
    let coords = Console.ReadLine().Split([|' '|]) |> Seq.map float |> List.ofSeq
    match coords with
    | [x;y] -> Point (x, y)
    | _ -> failwith "Invalid coordinates" 


[<EntryPoint>]
let main argv =
    let n = Console.ReadLine() |> int
    let points = [ for i in 1..n -> readPoint() ]
    printf "%f" (convexHullPerimeter points)
    //points |> Seq.map (fun (Point (x,y)) -> printfn "%f %f" x y) |> ignore
    0
    