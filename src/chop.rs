pub fn functional_chop(target: i32, elements: &[i32]) -> Option<usize> {
    elements.iter().position(|&element| target == element)
}

pub fn recursive_chop(target: i32, elements: &[i32]) -> Option<usize> {
    if elements.is_empty() {
        return None;
    }

    if elements.len() == 1 {
        if elements[0] == target {
            return Some(0);
        } else {
            return None;
        }
    }

    let pivot_index = elements.len() / 2;
    let pivot_element = elements[pivot_index];

    match target {
        x if x < pivot_element => recursive_chop(target, &elements[0..pivot_index]),
        x if x == pivot_element => Some(pivot_index),
        x if x > pivot_element => {
            recursive_chop(target, &elements[pivot_index..]).map(|i| pivot_index + i)
        }
        _ => panic!("Unreachable"),
    }
}
