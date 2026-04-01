# Compiler Design - 10 Marks Comprehensive Answers

## Unit 3

### 1) Define Attributed Grammar. Explain S-attributed and L-attributed Grammars with example.

An attributed grammar is a context-free grammar (CFG) augmented with attributes and semantic rules.

- Attributes store semantic information associated with grammar symbols.
- Semantic rules define how attribute values are computed.
- Attribute evaluation helps in type checking, intermediate code generation, declaration processing, and translation.

Types of attributes:

- Synthesized attribute: computed from attributes of children in the parse tree.
- Inherited attribute: computed from parent or siblings.

#### S-attributed grammar

A grammar is S-attributed if it uses only synthesized attributes.

- Evaluation is naturally bottom-up.
- Very suitable for LR parsing.

Example (expression value computation):

Grammar:

```text
E -> E1 + T
E -> T
T -> T1 * F
T -> F
F -> (E)
F -> num
```

Semantic rules:

```text
E -> E1 + T     { E.val = E1.val + T.val }
E -> T          { E.val = T.val }
T -> T1 * F     { T.val = T1.val * F.val }
T -> F          { T.val = F.val }
F -> (E)        { F.val = E.val }
F -> num        { F.val = num.lexval }
```

All attributes are synthesized (`val`), so this is S-attributed.

#### L-attributed grammar

A grammar is L-attributed if inherited attributes are allowed under this restriction:

For production `A -> X1 X2 ... Xn`, inherited attribute of `Xi` may depend only on:

- attributes of `A`, and
- attributes of `X1 ... X(i-1)` (symbols to its left).

This supports left-to-right evaluation and suits top-down parsing.

Example (declaration type propagation):

Grammar:

```text
D -> T L
T -> int
T -> float
L -> L1 , id
L -> id
```

Attributes:

- `T.type` is synthesized (`int` or `float`).
- `L.in` is inherited type from `T`.

Semantic rules:

```text
D -> T L         { L.in = T.type }
T -> int         { T.type = int }
T -> float       { T.type = float }
L -> L1 , id     { L1.in = L.in; addType(id.entry, L.in) }
L -> id          { addType(id.entry, L.in) }
```

Why L-attributed:

- Inherited attribute `L1.in` depends on parent/left context only.

Comparison:

- S-attributed: only synthesized, easiest for bottom-up.
- L-attributed: synthesized + restricted inherited, works with single left-to-right pass.

---

### 2) Explain control flow for various control structures.

Control flow determines execution order of statements. In intermediate code, control constructs are converted into labels and jumps.

#### (a) if statement

Source:

```text
if (B) S
```

Three-address style:

```text
if B goto Ltrue
goto Lnext
Ltrue: S
Lnext:
```

#### (b) if-else statement

```text
if (B) S1 else S2
```

```text
if B goto L1
goto L2
L1: S1
    goto Lnext
L2: S2
Lnext:
```

#### (c) while loop

```text
while (B) S
```

```text
Lbegin: if B goto Lbody
        goto Lnext
Lbody:  S
        goto Lbegin
Lnext:
```

#### (d) do-while loop

```text
do S while(B)
```

```text
Lbody: S
       if B goto Lbody
Lnext:
```

#### (e) for loop

```text
for (init; B; inc) S
```

```text
init
Ltest: if B goto Lbody
       goto Lnext
Lbody: S
Linc:  inc
       goto Ltest
Lnext:
```

#### (f) switch-case

General strategy:

- Evaluate switch expression once.
- Compare with case constants.
- Jump to matching label; else default.

```text
t = E
if t == c1 goto L1
if t == c2 goto L2
...
goto Ldefault
L1: S1; goto Lnext
L2: S2; goto Lnext
Ldefault: Sd
Lnext:
```

For dense case ranges, jump tables reduce comparisons.

#### Boolean expression flow

Boolean conditions are often compiled in short-circuit style:

- `B1 && B2`: if `B1` false, skip `B2`.
- `B1 || B2`: if `B1` true, skip `B2`.

This reduces unnecessary evaluation and supports side-effect correctness.

---

### 3) Translate `R = -(a+b)*(c+d)/(a+b+e*f)` into Quadruples, Triples, and Indirect Triples.

#### Three-address sequence

```text
t1 = a + b
t2 = uminus t1
t3 = c + d
t4 = t2 * t3
t5 = e * f
t6 = a + b
t7 = t6 + t5
t8 = t4 / t7
R  = t8
```

#### Quadruples

Format: `(op, arg1, arg2, result)`

| No  | op     | arg1 | arg2 | result |
| --- | ------ | ---- | ---- | ------ |
| 1   | +      | a    | b    | t1     |
| 2   | uminus | t1   | -    | t2     |
| 3   | +      | c    | d    | t3     |
| 4   | \*     | t2   | t3   | t4     |
| 5   | \*     | e    | f    | t5     |
| 6   | +      | a    | b    | t6     |
| 7   | +      | t6   | t5   | t7     |
| 8   | /      | t4   | t7   | t8     |
| 9   | =      | t8   | -    | R      |

#### Triples

Format: `(op, arg1, arg2)` where arguments can be names or result positions.

| Pos | op     | arg1 | arg2 |
| --- | ------ | ---- | ---- |
| 0   | +      | a    | b    |
| 1   | uminus | (0)  | -    |
| 2   | +      | c    | d    |
| 3   | \*     | (1)  | (2)  |
| 4   | \*     | e    | f    |
| 5   | +      | a    | b    |
| 6   | +      | (5)  | (4)  |
| 7   | /      | (3)  | (6)  |
| 8   | =      | (7)  | R    |

#### Indirect triples

Indirect triples use a pointer list to triples.

Pointer table:

| Index | Points to triple position |
| ----- | ------------------------- |
| p0    | 0                         |
| p1    | 1                         |
| p2    | 2                         |
| p3    | 3                         |
| p4    | 4                         |
| p5    | 5                         |
| p6    | 6                         |
| p7    | 7                         |
| p8    | 8                         |

Benefit:

- Reordering is done by changing pointer order, not triple contents.

---

### 4) Write three-address code for:

```text
while (A < C and B > D)
do
  if A = 1 then
     C = C + 1
  else
     while A <= D
     do
       A = A + B
```

A short-circuit and label-based TAC:

```text
L1: if A < C goto L2
    goto Lend
L2: if B > D goto L3
    goto Lend
L3: if A == 1 goto L4
    goto L5
L4: t1 = C + 1
    C = t1
    goto L1
L5: if A <= D goto L6
    goto L1
L6: t2 = A + B
    A = t2
    goto L5
Lend:
```

Notes:

- `and` is handled by two tests in sequence.
- Inner `while` is nested with labels `L5`, `L6`.

---

### 5) List and explain variants of syntax tree.

Common tree representations in intermediate form:

#### (a) Parse tree (concrete syntax tree)

- Contains all grammar symbols (terminals and non-terminals).
- Captures full derivation details.
- Used for syntax validation and teaching derivations.

#### (b) Abstract syntax tree (AST)

- Removes unnecessary grammar nodes.
- Keeps essential language constructs/operators.
- Compact and convenient for semantic analysis and code generation.

Example:

For `a + b * c`, AST root is `+`, with left `a`, right subtree `* (b,c)`.

#### (c) Directed acyclic graph (DAG) for expressions

- Similar to AST but shares common subexpressions.
- Avoids repeated computation.

For `(a+b) - (a+b)`, one node for `(a+b)` is shared by both uses.

#### (d) Syntax-directed translation tree / annotated tree

- Parse/AST nodes carry attributes and semantic info.
- Useful to explain type checking, widths, offsets, and code templates.

Comparison summary:

- Parse tree: most detailed, largest.
- AST: compact, compiler-friendly.
- DAG: optimization-oriented.
- Annotated tree: semantic-processing oriented.

---

### 6) State how to represent intermediate code and explain implementation of three-address code with example.

Intermediate code (IC) is machine-independent representation between front end and back end.

#### Forms of IC representation

- Postfix notation.
- Syntax trees / AST / DAG.
- Three-address code (most popular).

#### Three-address code (TAC)

TAC properties:

- At most one operator on RHS.
- Uses temporary names (`t1`, `t2`, ...).
- Easy to optimize and translate to assembly.

Typical TAC statements:

- `x = y op z`
- `x = op y`
- `x = y`
- `if x relop y goto L`
- `goto L`
- `param x`, `call p, n`, `return x`
- `x = y[i]`, `x[i] = y`

#### Implementing TAC in compiler

Data structures:

- Symbol table entries for identifiers and temporaries.
- Instruction array/list.
- `newtemp()` for new temporaries.
- `emit(op, arg1, arg2, res)` for instruction generation.

Pseudo-process for expression translation:

1. Translate subexpressions recursively.
2. Create temporary for each operator node.
3. Emit instruction using children results.
4. Return location name upward.

Example: `x = (a-b) + (c*d)`

```text
t1 = a - b
t2 = c * d
t3 = t1 + t2
x  = t3
```

Quadruple implementation:

| op  | arg1 | arg2 | result |
| --- | ---- | ---- | ------ |
| -   | a    | b    | t1     |
| \*  | c    | d    | t2     |
| +   | t1   | t2   | t3     |
| =   | t3   | -    | x      |

Benefits:

- Supports optimization (CSE, copy propagation, dead code elimination).
- Easy mapping to target instructions.

---

### 7) Explain backpatching with example for Boolean and flow-of-control statements.

Backpatching is a code generation technique used when jump targets are not yet known.

- Compiler emits incomplete jumps with blank labels.
- Maintains lists of such jump positions.
- Later fills target labels when destination becomes known.

Key lists:

- `truelist(B)`: jumps to execute when `B` is true.
- `falselist(B)`: jumps to execute when `B` is false.
- `nextlist(S)`: pending exits from statement `S`.

Operations:

- `makelist(i)`: create list with instruction `i`.
- `merge(p1,p2)`: combine lists.
- `backpatch(p, L)`: fill all instructions in list `p` with label `L`.

Example Boolean: `B = x < y || a < b`

Generated form (before patch):

```text
i1: if x < y goto _
i2: goto _
i3: if a < b goto _
i4: goto _
```

- `truelist(B) = merge({i1}, {i3})`
- `falselist(B) = {i4}` after patching `i2` to start of second operand.

Example control statement:

```text
if (B) S1 else S2
```

Steps:

1. Generate code for `B` with `truelist` and `falselist`.
2. Backpatch `truelist(B)` to start label of `S1`.
3. Backpatch `falselist(B)` to start label of `S2`.
4. Merge `nextlist(S1)` and `nextlist(S2)` as `nextlist` of entire statement.

Advantages:

- Works in one pass with syntax-directed translation.
- Clean handling of nested conditionals and loops.

---

### 8) Explain intermediate code for procedures with an example.

Procedure-related intermediate code must capture call/return behavior and parameter passing.

Typical TAC operations:

- `beginproc p`
- `param x`
- `call p, n`
- `t = call p, n` (function return)
- `return x`
- `endproc`

Also includes local variable management and temporaries.

Example source:

```text
int sum(int a, int b) {
  int c;
  c = a + b;
  return c;
}

x = sum(p, q);
```

Intermediate code:

```text
beginproc sum
  t1 = a + b
  c  = t1
  return c
endproc

param p
param q
t2 = call sum, 2
x  = t2
```

Important runtime aspects reflected by IC:

- Argument passing order.
- Return value transfer.
- Control transfer to callee and back to caller.
- Activation record setup/teardown in target code generation phase.

---

## Unit 4

### 1) Explain principal sources of optimization techniques in detail with example.

Compiler optimization improves code quality without changing meaning.

Principal sources:

#### (a) Redundant computation elimination

- Common Subexpression Elimination (CSE)
- Example:

```text
x = a*b + c
y = a*b + d
```

`a*b` computed once.

#### (b) Compile-time evaluation

- Constant folding: `3*4 -> 12`
- Constant propagation: if `x=10`, replace uses with `10`.

#### (c) Copy and algebraic simplification

- Copy propagation: `x=y; z=x+1` -> `z=y+1`
- Algebraic identities: `x+0 -> x`, `x*1 -> x`, `x*0 -> 0`.

#### (d) Dead code elimination

- Remove computations whose results are never used.

#### (e) Code motion

- Move loop-invariant computation outside loop.

#### (f) Strength reduction

- Replace costly operations with cheaper ones.
- Example: multiplication by 2 replaced by addition or shift.

#### (g) Induction variable optimization

- Replace repeated expression by running updates.

#### (h) Register optimization

- Keep frequently used variables in registers.

#### (i) Control-flow optimization

- Remove unreachable blocks.
- Simplify jumps (`goto L1; L1:` patterns).

Overall effect:

- Fewer instructions.
- Reduced memory traffic.
- Better runtime and code size.

---

### 2) Define and explain basic blocks and flow graphs with an example.

#### Basic block

A basic block is a maximal sequence of consecutive statements with:

- one entry point (first statement),
- one exit point (last statement),
- no branches except at end,
- no branch targets except first statement.

#### Leaders (to find blocks)

A statement is a leader if:

1. it is the first statement,
2. it is the target of a jump,
3. it follows a jump statement.

#### Flow graph

- Nodes: basic blocks.
- Directed edge `B1 -> B2` if control may transfer from `B1` to `B2`.

Example TAC:

```text
1: i = 1
2: sum = 0
3: if i > 10 goto 8
4: sum = sum + i
5: i = i + 1
6: goto 3
8: print sum
```

Basic blocks:

- `B1`: (1,2)
- `B2`: (3)
- `B3`: (4,5,6)
- `B4`: (8)

Edges:

- `B1 -> B2`
- `B2 -> B3` (if condition false)
- `B2 -> B4` (if true)
- `B3 -> B2`

Uses:

- Foundation for local/global optimization.
- Data-flow analysis and loop detection.

---

### 3) Explain loop optimization techniques with example.

Loops dominate runtime, so optimizing loops gives major gains.

#### (a) Loop-invariant code motion

If expression does not change across iterations, move it outside loop.

```text
for i=1..n:
  t = a*b
  x[i] = t + i
```

Move `t=a*b` before loop.

#### (b) Strength reduction

Replace expensive computation by incremental update.

```text
t = 4*i
```

Inside loop, maintain `t = t + 4`.

#### (c) Induction variable elimination

If one induction variable is derivable from another, remove extras.

#### (d) Loop unrolling

Replicate loop body to reduce branch overhead.

- Improves ILP but may increase code size.

#### (e) Loop fusion (jamming)

Combine adjacent loops with same bounds.

- Improves cache locality.

#### (f) Loop fission (distribution)

Split loop to isolate independent parts.

- Can improve vectorization/cache behavior.

#### (g) Loop interchange

Swap nested loop order for better memory access pattern.

#### (h) Loop unswitching

Move invariant condition outside loop and duplicate loop body by branch.

Benefits:

- Lower per-iteration cost.
- Better cache and register use.
- Increased pipeline/vector performance.

---

### 4) Explain various structure-preserving transformations with suitable example.

Structure-preserving transformations improve code while preserving high-level control structure and readability of intermediate representation.

Common transformations:

#### (a) Common subexpression elimination

```text
t1 = a+b
t2 = a+b
```

Second replaced by `t2 = t1`.

#### (b) Copy propagation

`x=y; z=x+1` -> `z=y+1`.

#### (c) Dead code elimination

Remove statements whose results are never used.

#### (d) Constant folding/propagation

`x=5; y=x+3` -> `y=8`.

#### (e) Algebraic simplification

`x=x+0`, `y=y*1`, `z=z-z -> 0`.

#### (f) Reassociation and canonicalization

Reorder associative operations to expose optimization opportunities.

#### (g) Jump optimization

- Eliminate jump-to-jump chains.
- Remove unreachable labels/blocks.

Example sequence:

Before:

```text
x = a + b
y = a + b
z = y * 1
if true goto L1
goto L2
L1: w = z + 0
L2:
```

After:

```text
x = a + b
y = x
w = y
```

(unreachable and neutral operations removed)

---

### 5) Explain construction of DAG for a basic block.

DAG (Directed Acyclic Graph) represents value computation in a basic block and enables local optimization.

Construction rules:

1. Create leaves for unique identifiers/constants.
2. For statement `x = y op z`:
   - find/create node `op(y,z)`.
   - attach `x` as label to that node.
3. For copy `x=y`, attach label `x` to node of `y`.
4. If `op(y,z)` already exists, reuse node (captures common subexpression).

Example block:

```text
a = b + c
d = b + c
e = a - d
```

DAG:

- one `+` node with children `b`,`c` labeled `{a,d}`
- one `-` node with both operands pointing to same `+` node, labeled `{e}`

Optimization insights:

- `d = b + c` redundant.
- Since `a` and `d` same value, `e = a-d` simplifies to `0`.

Code regenerated from DAG is shorter and faster.

---

### 6) Explain various structure-preserving transformations with suitable examples.

(Repeated question; expanded answer format)

Transformations preserving semantics and control structure:

1. Local value numbering and CSE.
2. Constant folding and constant propagation.
3. Copy propagation.
4. Dead assignment elimination.
5. Algebraic simplification.
6. Boolean simplification (`if (true)` / `if (false)`).
7. Jump threading and unreachable code removal.

Illustrative example:

Before:

```text
t1 = a * 1
t2 = b + c
t3 = b + c
x = t2 + 0
y = t1 + x
```

After:

```text
t2 = b + c
y = a + t2
```

Effects:

- fewer instructions,
- reduced temporaries,
- same behavior.

---

### 7) Explain Data Flow Analysis in detail.

Data Flow Analysis (DFA) computes information about possible program states at each point in control flow graph.

Components:

- CFG with basic blocks.
- Direction: forward or backward.
- Domain: sets of facts (definitions, expressions, variables).
- Transfer functions: how block transforms IN facts to OUT facts.
- Meet operator: merge from multiple predecessors/successors.

General framework:

For forward analysis:

```text
IN[B]  = meet of OUT[pred(B)]
OUT[B] = fB(IN[B])
```

For backward analysis:

```text
OUT[B] = meet of IN[succ(B)]
IN[B]  = fB(OUT[B])
```

Iterate to fixed point.

Major analyses:

#### (a) Reaching definitions (forward, may)

Definition `d` reaches point `p` if there is a path where `d` not killed.

- Used in constant propagation and use-definition chains.

#### (b) Live variable analysis (backward, may)

Variable is live at point if its current value may be used later.

- Used in register allocation.

Equations:

```text
IN[B]  = USE[B] U (OUT[B] - DEF[B])
OUT[B] = U IN[s], s in succ(B)
```

#### (c) Available expressions (forward, must)

Expression available if already computed on all paths and operands unchanged.

- Used in CSE.

#### (d) Very busy expressions (backward, must)

Expression definitely used before operand redefinition.

- Supports code motion.

Challenges:

- Loops require iterative convergence.
- Trade-off between precision and compile time.

---

### 8) Explain loop optimizations for a flow graph and give optimized flow graph.

Approach on any loop-containing CFG:

1. Identify back edges using dominators.
2. Form natural loops.
3. Apply safe transformations.
4. Rebuild optimized CFG.

Typical transformations on loop CFG:

- Move loop-invariant computations to preheader.
- Eliminate redundant expressions in loop body.
- Strength-reduce induction expressions.
- Remove dead updates.
- Simplify branches.

Illustrative loop (original):

```text
B1: i=0; t=a*b
B2: if i>=n goto B5
B3: x[i]=a*b + i
B4: i=i+1; goto B2
B5: exit
```

Optimized:

```text
P : t=a*b         (preheader)
B2: if i>=n goto B5
B3: x[i]=t+i
B4: i=i+1; goto B2
B5: exit
```

Optimized flow graph:

- New preheader `P` inserted before loop header.
- Edge sequence: `P -> B2`, `B2 -> B3`, `B3 -> B4`, `B4 -> B2`, `B2 -> B5`.

Advantages:

- Reduced repeated computation.
- Smaller loop body and better performance.

---

## Unit 5

### 1) Explain storage organization in brief by considering static vs dynamic storage allocation.

Runtime memory is commonly organized into:

- Code/Text segment
- Static/Global data
- Heap (dynamic objects)
- Stack (procedure activations)

#### Static storage allocation

- Memory fixed at compile time.
- Addresses do not change during execution.
- Used for global variables, static locals, constants.

Pros:

- Very fast access.
- No runtime allocation overhead.

Cons:

- Poor flexibility.
- Cannot support recursion-dependent local instances dynamically.

#### Dynamic storage allocation

Allocated at runtime.

Two forms:

- Stack dynamic: activation records for procedure calls.
- Heap dynamic: objects with arbitrary lifetime (`new`, `malloc`).

Pros:

- Supports recursion and dynamic data structures.
- Better memory utilization for varying runtime needs.

Cons:

- Allocation/deallocation overhead.
- Fragmentation and lifetime management complexity.

Comparison summary:

- Static: fixed lifetime and address.
- Dynamic: runtime lifetime and often runtime address.

---

### 2) Write in detail about activation records.

Activation record (AR), or stack frame, stores information for one procedure invocation.

Typical fields:

1. Actual parameters / argument area
2. Return value (if needed)
3. Return address
4. Control link (dynamic link to caller frame)
5. Access link (static link for nested scope access)
6. Saved machine registers
7. Local variables
8. Temporaries / spill area

Lifecycle:

- On call: new AR pushed, links set, control transfers to callee.
- On return: result passed, previous environment restored, AR popped.

Pointers:

- `SP` (stack pointer): top of stack.
- `FP`/`BP` (frame/base pointer): stable reference to current frame.

Why AR is needed:

- Handles recursion (multiple active calls).
- Isolates local variables per call.
- Supports parameter passing and return mechanism.

Calling sequence (simplified):

1. Caller evaluates arguments.
2. Caller places arguments and call instruction.
3. Callee prologue creates frame and saves state.
4. Callee body executes.
5. Callee epilogue restores state and returns.
6. Caller resumes.

---

### 3) Explain code generation algorithm in detail.

Code generation maps intermediate representation to target machine code.

Inputs:

- IR (usually TAC/basic blocks),
- symbol table,
- target machine description (registers, instruction set).

Goals:

- Correctness,
- efficiency (speed and size),
- good register utilization.

Basic algorithm (block-oriented):

1. Partition IR into basic blocks.
2. For each block, compute next-use/live information.
3. For each TAC instruction:
   - choose target instruction pattern,
   - choose registers for operands/results,
   - spill if registers unavailable,
   - emit machine code.
4. Emit block control transfers.
5. Handle procedure prologue/epilogue.

Register and address descriptors:

- Register descriptor: which variable value is in each register.
- Address descriptor: where current value of variable resides (register/memory).

Heuristics:

- Keep frequently used live values in registers.
- Prefer instruction forms matching machine addressing modes.
- Delay stores to memory when safe.

Example TAC:

```text
t1 = a + b
c  = t1 * d
```

Possible target-like sequence:

```text
LOAD R1, a
ADD  R1, b
MUL  R1, d
STORE c, R1
```

Quality improvements:

- Instruction selection via tree-pattern matching.
- Better register allocation (graph coloring/linear scan).
- Peephole optimization after emission.

---

### 4) Explain various forms of object code.

Object code is machine-level output produced by compiler/assembler before or after linking.

Forms:

#### (a) Absolute machine code

- Contains final physical addresses.
- Load at fixed location only.
- Rare in modern systems.

#### (b) Relocatable object code

- Addresses are relative.
- Linker/loader adjusts addresses during linking/loading.
- Most common form (`.o`, `.obj`).

Contains:

- text and data sections,
- symbol table,
- relocation information,
- external references.

#### (c) Assembly code (symbolic object form)

- Human-readable low-level form.
- Requires assembler to convert to machine code.

#### (d) Shared object / dynamic library code

- Position-independent code for runtime linking.
- Enables library reuse and memory sharing.

Pipeline context:

```text
Source -> Compiler -> Assembly/Object -> Linker -> Executable -> Loader
```

---

### 5) Explain various runtime storage allocation strategies.

Main strategies:

#### (a) Static allocation

- Compile-time assignment.
- Fixed addresses for entire execution.
- Suitable for globals, fixed-size data.

#### (b) Stack allocation

- LIFO strategy aligned with call/return nesting.
- Each call pushes activation record; return pops it.
- Efficient and simple.

Best for:

- local variables with lexical lifetime.
- recursion support.

Limitation:

- Not suitable for data surviving after function returns.

#### (c) Heap allocation

- Arbitrary allocation/deallocation order.
- Supports dynamic structures: linked lists, trees, graphs, objects.

Memory management methods:

- Explicit deallocation (`free/delete`).
- Garbage collection.

Issues:

- Fragmentation,
- allocation overhead,
- leaks/dangling pointers (manual management).

Practical systems use a combination:

- globals in static,
- procedure locals in stack,
- dynamic objects in heap.

---

### 6) Explain procedure calls and displays in brief.

Procedure call implementation requires passing control, data, and environment.

Call essentials:

- argument passing,
- return address handling,
- activation record creation,
- restoration on return.

#### Parameter passing modes

- Call by value.
- Call by reference.
- Call by value-result (copy-in/copy-out).
- Call by name (historical).

#### Accessing non-local variables

In nested procedures, non-local variables need static-scope access.

Two techniques:

1. Static links (access links)

- Each frame points to frame of lexical parent.
- Non-local access follows link chain.

2. Displays

- Display is an array where entry `k` points to most recent frame at nesting level `k`.
- Non-local access becomes direct indexed lookup (faster than long chain traversal).

Display advantages:

- Faster access for deeply nested scopes.

Display cost:

- Must save/restore display entries on call/return.

---

### 7) Explain the concept of register allocation and assignments.

Register allocation decides which variables reside in limited CPU registers at each point.

Register assignment maps allocated variables to specific registers.

Why important:

- Register access is much faster than memory.
- Good allocation strongly affects performance.

#### Core ideas

- Live range: program region where value may be used.
- Interference: two live ranges overlap, cannot share register.
- Spill: store value to memory when registers insufficient.

#### Techniques

1. Graph coloring allocation

- Build interference graph.
- Color with `k` colors (registers).
- Uncolorable nodes are spilled.

2. Linear scan allocation

- Sort intervals by start point.
- Allocate quickly with active set.
- Popular in JIT compilers.

#### Register assignment heuristics

- Prefer frequently used variables.
- Prefer values live across many instructions.
- Avoid unnecessary load/store by keeping operands in same register when possible.

Example:

```text
t1 = a+b
t2 = t1+c
```

If `t1` remains in same register, second instruction avoids reload.

---

### 8) Give various issues in the design of code generator.

Major design issues:

1. Input representation

- Quality and structure of IR (three-address code, SSA, trees).

2. Target machine characteristics

- Register count,
- instruction formats,
- addressing modes,
- condition code behavior.

3. Instruction selection

- Choosing efficient machine instruction sequence.

4. Register allocation and spilling

- Balancing performance vs spill overhead.

5. Order of evaluation

- Minimize register pressure and memory traffic.

6. Memory management and data layout

- Stack frame layout,
- global/local addressing,
- alignment.

7. Control flow and branch generation

- Efficient jumps, fall-through usage, branch prediction friendliness.

8. Procedure call conventions

- Caller/callee saved registers,
- parameter passing,
- return value handling.

9. Code quality trade-offs

- Compile-time vs runtime performance,
- speed vs size optimization.

10. Machine-dependent optimizations

- Peephole optimization,
- scheduling,
- exploiting special instructions.

11. Correctness and portability

- Preserve semantics under all optimizations.
- Handle edge cases (overflow, exceptions, aliasing assumptions).

A robust code generator balances correctness first, then performance and size under machine constraints.

---

## Quick Exam Writing Tips (for 10 marks)

1. Start with a formal definition in 2-3 lines.
2. Draw or describe one clear example.
3. Add algorithm/steps where applicable.
4. Mention advantages, limitations, and use-cases.
5. End with a concise summary line.

This structure generally helps secure full or near-full marks.
