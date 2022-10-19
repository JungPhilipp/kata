pub fn functional_chop(target: i32, elements: &[i32]) -> Option<usize> {
    elements.iter().position(|&element| element == target)
}
