type date = int * int * int

(* let getNumberList (splitChar: char): int list =
  let _ = read_line () |> int_of_string in  (* 첫 번째 줄의 숫자 개수는 무시 *)
  let numbers = read_line () in
  let numberList = String.split_on_char splitChar numbers |> List.map int_of_string in
  numberList *)

let getDate () : date =
  let date = read_line () in
  let dateList = String.split_on_char '-' date |> List.map int_of_string in
  match dateList with
  | [y; m; d] -> (y, m, d)
  | _ -> failwith "Invalid date format"

let getNumber () : int = read_line () |> int_of_string

let orderDate (date1: date) (date2: date) : bool = 
  match (date1, date2) with
  | ((y1, m1, d1), (y2, m2, d2)) when y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 <= d2) -> true
  | _ -> false

let solve () : unit =
  let dateNow = getDate () in 
  let n = getNumber () in
  let rec auxGetDatesNumber (n: int) (dateNow: date) : int =
    match n with
    | 0 -> 0
    | _ -> 
      let date = getDate () in
      if orderDate dateNow date then 1 + auxGetDatesNumber (n - 1) dateNow
      else auxGetDatesNumber (n - 1) dateNow
    in
  let result = auxGetDatesNumber n dateNow in
  print_int result

let _ = solve ()