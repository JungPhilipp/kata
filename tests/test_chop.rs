use taka::chop::{functional_chop, imperative_chop, recursive_chop};

#[test]
fn test_functional_chop() {
    test_chop(functional_chop);
}

#[test]
fn test_recursive_chop() {
    test_chop(recursive_chop);
}

#[test]
fn test_imperative_chop() {
    test_chop(imperative_chop);
}

fn test_chop(chop: fn(i32, &[i32]) -> Option<usize>) {
    assert_eq!(None, chop(3, &[]));
    assert_eq!(None, chop(3, &[1]));
    assert_eq!(Some(0), chop(1, &[1]));

    assert_eq!(Some(0), chop(1, &[1, 3, 5]));
    assert_eq!(Some(1), chop(3, &[1, 3, 5]));
    assert_eq!(Some(2), chop(5, &[1, 3, 5]));

    assert_eq!(None, chop(0, &[1, 3, 5]));
    assert_eq!(None, chop(2, &[1, 3, 5]));
    assert_eq!(None, chop(4, &[1, 3, 5]));
    assert_eq!(None, chop(6, &[1, 3, 5]));

    assert_eq!(Some(0), chop(1, &[1, 3, 5, 7]));
    assert_eq!(Some(1), chop(3, &[1, 3, 5, 7]));
    assert_eq!(Some(2), chop(5, &[1, 3, 5, 7]));
    assert_eq!(Some(3), chop(7, &[1, 3, 5, 7]));

    assert_eq!(None, chop(0, &[1, 3, 5, 7]));
    assert_eq!(None, chop(2, &[1, 3, 5, 7]));
    assert_eq!(None, chop(4, &[1, 3, 5, 7]));
    assert_eq!(None, chop(6, &[1, 3, 5, 7]));
    assert_eq!(None, chop(8, &[1, 3, 5, 7]));
}
