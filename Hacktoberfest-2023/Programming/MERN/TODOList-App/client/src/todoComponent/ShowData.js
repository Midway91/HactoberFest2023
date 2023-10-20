const ShowData = ({ item, onSelect }) => {
    return (
        <>
            <li className="list">
                <button onClick={() => { onSelect(item._id) }} title="Delete"> x </button>
                <p>{item.data}</p>
            </li>
            <hr />
        </>
    );
}

export default ShowData;