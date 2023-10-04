const DataAdder = ({ item, setItem, placeholderText, click }) => {
    return (
        <>
            <div className="data_input">
                <input type="text" onChange={(e) => setItem({ data: e.target.value })} value={item.data} placeholder={placeholderText} />
                <button onClick={click} title="Add">+</button>
            </div>
        </>
    );
}
export default DataAdder;