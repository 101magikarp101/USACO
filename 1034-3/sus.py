import math, sys
sys.setrecursionlimit(10_000)

# global best squared radius and best shape found so far
best_sq_r = float('inf')
best_shape = None

# problem size
n = 13

# 4 corner offsets of a unit square centered at integer (x,y)
corner_offsets = [(-0.5, -0.5), (-0.5, +0.5),
                  (+0.5, -0.5), (+0.5, +0.5)]

# 4‐connectivity for growing the polyomino
dirs = [(1,0),(-1,0),(0,1),(0,-1)]


def mec_sq_radius(pts):
    """
    Return the squared radius of the minimal enclosing circle
    of a small list of points 'pts' using a 
    2‐point‐first heuristic, then 3‐point only if necessary.
    """
    m = len(pts)
    if m < 2:
        return 0.0

    best = float('inf')
    # Try every 2‐point circle
    for i in range(m):
        x1,y1 = pts[i]
        for j in range(i+1, m):
            x2,y2 = pts[j]
            # center = midpoint
            cx = 0.5*(x1 + x2)
            cy = 0.5*(y1 + y2)
            # squared radius = dist^2/4
            r2 = ((x1-x2)**2 + (y1-y2)**2)*0.25
            if r2 >= best:
                continue
            # check all pts inside
            ok = True
            for (x,y) in pts:
                if (x-cx)**2 + (y-cy)**2 > r2 + 1e-9:
                    ok = False
                    break
            if ok:
                best = r2

    if best < float('inf'):
        return best

    # otherwise try every triple
    for i in range(m):
        x1,y1 = pts[i]
        for j in range(i+1, m):
            x2,y2 = pts[j]
            for k in range(j+1, m):
                x3,y3 = pts[k]
                d = 2*(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))
                if abs(d) < 1e-12:
                    continue
                ux = ((x1*x1+y1*y1)*(y2-y3) +
                      (x2*x2+y2*y2)*(y3-y1) +
                      (x3*x3+y3*y3)*(y1-y2)) / d
                uy = ((x1*x1+y1*y1)*(x3-x2) +
                      (x2*x2+y2*y2)*(x1-x3) +
                      (x3*x3+y3*y3)*(x2-x1)) / d
                r2 = (ux-x1)**2 + (uy-y1)**2
                if r2 >= best:
                    continue
                ok = True
                for (x,y) in pts:
                    if (x-ux)**2 + (y-uy)**2 > r2 + 1e-9:
                        ok = False
                        break
                if ok:
                    best = r2

    return best


def search(shape, corners, max_sq_d, boundary):
    """
    DFS the connected shapes of size up to n,
    pruning whenever max_sq_d/4 >= best_sq_r.
    - shape:   set of (x,y) centers chosen so far
    - corners: list of all corner‐points of those squares
    - max_sq_d: current maximum squared pairwise distance among corners
    - boundary: set of next candidate centers to try
    """
    global best_sq_r, best_shape

    # lower‐bound check (radius >= sqrt(max_sq_d)/2)
    if max_sq_d * 0.25 >= best_sq_r:
        return

    if len(shape) == n:
        # compute exact MEC squared‐radius
        r2 = mec_sq_radius(corners)
        if r2 < best_sq_r:
            best_sq_r = r2
            best_shape = set(shape)
        return

    # try each possible extension (could sort to try promising ones first)
    for (x,y) in list(boundary):
        # add this square
        shape.add((x,y))
        # snapshot corners for backtrack
        old_len = len(corners)
        old_max = max_sq_d

        # add its 4 corners, update max_sq_d incrementally
        for dx,dy in corner_offsets:
            nx, ny = x+dx, y+dy
            for (cx,cy) in corners:
                d2 = (nx-cx)**2 + (ny-cy)**2
                if d2 > max_sq_d:
                    max_sq_d = d2
            corners.append((nx,ny))

        # expand boundary by neighbours of (x,y)
        new_neigh = {(x+dx,y+dy) for dx,dy in dirs}
        new_b = (boundary | new_neigh) - shape

        # recurse
        search(shape, corners, max_sq_d, new_b)

        # backtrack
        shape.remove((x,y))
        del corners[old_len:]
        max_sq_d = old_max

        # also remove (x,y) from future boundary
        boundary.discard((x,y))


# initialize
start_shape = {(0,0)}
start_corners = [(dx,dy) for dx,dy in map(lambda o:(0.5*o[0],0.5*o[1]), corner_offsets)]
start_max_sq = 0.0
# actually we need the 4 corners of (0,0):
start_corners = [ (dx,dy) for dx,dy in [(-0.5,-0.5),(-0.5,0.5),(0.5,-0.5),(0.5,0.5)] ]

start_boundary = {(1,0),(-1,0),(0,1),(0,-1)}

# run the search
search(start_shape, start_corners, start_max_sq, start_boundary)

print("Best radius:", math.sqrt(best_sq_r))
print("Best shape centers:", best_shape)
