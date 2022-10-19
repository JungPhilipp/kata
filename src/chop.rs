pub fn functional_chop(target: i32, elements: &[i32]) -> Option<usize> {
    elements.iter().position(|&element| target == element)
}

pub fn recursive_chop(target: i32, elements: &[i32]) -> Option<usize> {
    match elements.len() {
        0 => None,
        1 => {
            if elements[0] == target {
                Some(0)
            } else {
                None
            }
        }
        _ => {
            let pivot_index = elements.len() / 2;
            let pivot_element = elements[pivot_index];

            match target {
                x if x < pivot_element => recursive_chop(target, &elements[0..pivot_index]),
                x if x == pivot_element => Some(pivot_index),
                x if x > pivot_element => {
                    recursive_chop(target, &elements[pivot_index..]).map(|i| pivot_index + i)
                }
                _ => unreachable!("Match is exhaustive")
            }
        }
    }
}

pub fn imperative_chop(target: i32, elements: &[i32]) -> Option<usize> {
    let mut lower_index = 0;
    let mut upper_index = elements.len();
    loop {
        if lower_index == upper_index {
            return None;
        } else if lower_index + 1 == upper_index {
            if elements[lower_index] == target {
                return Some(lower_index);
            } else {
                return None;
            }
        }
        let pivot_index = lower_index + (upper_index - lower_index) / 2;
        let pivot_element = elements[pivot_index];
        match target {
            x if x < pivot_element => upper_index = pivot_index,
            x if x == pivot_element => return Some(pivot_index),
            x if x > pivot_element => lower_index = pivot_index,
            _ => unreachable!("Match is exhaustive")
        }
    }
}
