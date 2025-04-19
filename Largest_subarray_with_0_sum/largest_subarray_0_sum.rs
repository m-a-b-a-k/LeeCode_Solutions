use::std::collections::HashMap;
use::std::cmp::max;
use::std::vec::Vec;
use::std::i32;
fn largest_subarray_with_0_sum(arr: Vec<i32>) -> i32 {
    let mut sum_map = HashMap::new();
    let mut max_length = 0;
    let mut sum = 0;

    for (i, &num) in arr.iter().enumerate() {
        sum += num;

        if sum == 0 {
            max_length = max(max_length, (i + 1) as i32);
        }

        if let Some(&prev_index) = sum_map.get(&sum) {
            max_length = max(max_length, (i - prev_index) as i32);
        } else {
            sum_map.insert(sum, i);
        }
    }

    max_length
}
fn main() {
    let arr = vec![1, -1, 2, -2, 3, -3, 4, -4];
    let result = largest_subarray_with_0_sum(arr);
    println!("Length of the largest subarray with sum 0: {}", result);
}