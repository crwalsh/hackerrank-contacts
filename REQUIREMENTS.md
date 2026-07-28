# Contacts Trie Project Requirements

## Objective

Implement the HackerRank **Data Structures → Trie → Contacts** problem in C:

<https://www.hackerrank.com/challenges/contacts/problem>

In addition to HackerRank's `add` and `find` operations, implement a `search`
operation that checks whether a complete word is stored in the trie.

## Required Files

The final ZIP submission must contain:

- `contacts.c` — the commented C source code.
- `Makefile` — use the single-source C project Makefile provided in Canvas.
- `input1.txt` through `input10.txt` — ten meaningful test inputs.
- `output1.txt` through `output10.txt` — the matching expected outputs.
- A PDF debugging report only if the solution does not pass HackerRank.

## Required Code Definitions

The following definitions must appear in `contacts.c`:

```c
#define ALPHABET_LENGTH    26
#define OPERATION_BUF_SIZE  7 /* Large enough to cover the word 'search' and '\0' */
#define NAME_BUF_SIZE      22

/* Basic trie node */
typedef struct node {
    /* The number of words in the trie that contain the prefix down to and
       including the current letter. */
    int prefix_count;
    /* Allocate +1 for the the pointer to the end-of-string marker. Needed
       for the search feature. */
    struct node *children[ALPHABET_LENGTH + 1];
} trie_node;
```

## Input and Operation Behavior

- Read the number of operations first.
- Read each operation and name in the same format used by HackerRank.
- Support these operations:
  - `add name`: Add `name` to the trie.
  - `find prefix`: Print the number of stored names beginning with `prefix`.
  - `search name`: Test whether the entire `name` is stored.
- For `search`, print:
  - `yes` when the complete word exists.
  - `no` when the complete word does not exist.
- A stored word's prefix is not automatically a successful full-word search.
  For example, after `add superhero`:
  - `search superhero` prints `yes`.
  - `search super` prints `no`.

## Implementation Requirements

- Use a trie and the required `trie_node` structure.
- Use `prefix_count` to support prefix-count queries.
- Use the extra child pointer at index `ALPHABET_LENGTH` as the end-of-string
  marker needed by full-word search.
- Comment the source code so the implementation and reusable techniques are
  clear.
- Include every team member's name in a comment at the top of `contacts.c`.
- Free all dynamically allocated memory before the program terminates.
- The program must compile and run on the Linux Lab environment.
- The program should pass both HackerRank tests and additional instructor
  tests.
- The program should report no memory leaks when checked with Valgrind.

## Test Requirements

Submit ten meaningful input/output pairs that cover a wide range of behavior.
The test suite should include:

- Adding and finding one name.
- Multiple names sharing a prefix.
- Prefixes that do not exist.
- Searching for an exact stored word.
- Searching for a prefix that is not itself stored.
- Searching for a word that was never added.
- A word that is both stored and a prefix of a longer stored word.
- Repeated `find` and `search` operations.
- Names with very short and near-maximum supported lengths.
- A larger mixed sequence of `add`, `find`, and `search` operations.

Each `outputN.txt` file must contain exactly the output expected from the
matching `inputN.txt`.

## Team and Submission Notes

- Teams may contain up to three people.
- Put all team members' names at the top of `contacts.c`.
- Also include the team members' names in a Canvas submission comment.
- Upload one ZIP file containing all required deliverables.

## Conditional Debugging PDF

If the program does not pass HackerRank, include a PDF explaining:

- The type of HackerRank error encountered.
- The intended algorithm and implementation approach.
- The local tests run and any incorrect output observed.
- Relevant corner cases considered.
- The tracing and debugging process used.

## Final Checklist

- [ ] Source file is named exactly `contacts.c`.
- [ ] Team-member comment is present at the top of the source file.
- [ ] Required constants and `trie_node` definition are unchanged.
- [ ] `add`, `find`, and `search` behave as specified.
- [ ] Source code is commented.
- [ ] All allocated memory is freed.
- [ ] Canvas-provided `Makefile` is included.
- [ ] Ten numbered input files are included.
- [ ] Ten matching numbered expected-output files are included.
- [ ] Local build and all tests pass.
- [ ] Valgrind reports no memory leaks.
- [ ] Debugging PDF is included if HackerRank does not pass.
- [ ] All files are packaged in the submission ZIP.
