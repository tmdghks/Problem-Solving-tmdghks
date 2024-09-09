(* let getNumberList (splitChar: char): int list =
  let _ = read_line () |> int_of_string in  (* 첫 번째 줄의 숫자 개수는 무시 *)
  let numbers = read_line () in
  let numberList = String.split_on_char splitChar numbers |> List.map int_of_string in
  numberList *)

let getNumber () : int = read_line () |> int_of_string

type character = { level: int; status: int }

let compare_characters c1 c2 = compare c2.level c1.level

let rec get_character_list n =
  if n = 0 then []
  else
    let level = read_line () |> int_of_string in
    let status =
      match level with
      | level when level >= 250 -> 5
      | level when level >= 200 -> 4
      | level when level >= 140 -> 3
      | level when level >= 100 -> 2
      | level when level >= 60 -> 1
      | _ -> 0 in
    { level = level; status = status } :: get_character_list (n - 1)

let rec take n list =
  if n = 0 then []
  else
    match list with
    | [] -> []
    | hd :: tl -> hd :: take (n - 1) tl

let solve () : unit = 
  let n = getNumber () in
  let getOnly42 character_list =
    if List.length character_list >= 42 then
      take 42 character_list
    else
      character_list in
  let character_list = get_character_list n |> List.sort compare_characters |> getOnly42 in
  let total_level = List.fold_left (fun acc character -> acc + character.level) 0 character_list in
  let total_status = List.fold_left (fun acc character -> acc + character.status) 0 character_list in
  print_int total_level; print_string " "; print_int total_status

let _ = solve ()