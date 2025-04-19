//use std::collections::HashMap;
// Function to count the number of subarrays with a given XOR
fn count_sub_arrays_xor(arr: Vec<i32>, k: i32) -> i32 {
    let mut count = 0;
    let mut xor_map = std::collections::HashMap::new();
    let mut current_xor = 0;

    for &num in arr.iter() {
        current_xor ^= num;

        if current_xor == k {
            count += 1;
        }

        if let Some(&prev_count) = xor_map.get(&(current_xor ^ k)) {
            count += prev_count;
        }

        *xor_map.entry(current_xor).or_insert(0) += 1;
    }

    count
}
fn main() {
    let arr = vec![4, 2, 2, 6, 4];
    let k = 6;
    let result = count_sub_arrays_xor(arr, k);
    println!("Count of subarrays with XOR {}: {}", k, result);
}