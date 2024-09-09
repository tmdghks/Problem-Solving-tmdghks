let getNumberList () : int list =
  let _ = read_line () |> int_of_string in  (* 첫 번째 줄의 숫자 개수는 무시 *)
  let numbers = read_line () in
  let numberList = String.split_on_char ' ' numbers |> List.map int_of_string in
  numberList

let rec printPreviousLevel (levelList: int list) =
  match levelList with
  | [] -> ()
  | h::t -> 
    begin
      match h / 25 with
      | 12 -> print_string "1 "
      | 11 -> print_string "2 "
      | 10 -> print_string "3 "
      | _ -> print_string "4 "
    end;
    printPreviousLevel t

let () =
  let numberList = getNumberList () in
  printPreviousLevel numberList